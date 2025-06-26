### **Complete WinDbg Tutorial: Crash Dump Analysis Mastery**  
*For Windows 10/11 | Version: WinDbg Preview (Modern UI)*  

---

#### **Step 1: Installation & Setup**  
1. **Install WinDbg Preview**  
   - Microsoft Store → Search "WinDbg Preview" → Install  
   *Alternative:* Download [Windows SDK](https://developer.microsoft.com/windows/downloads/windows-sdk/) (select "Debugging Tools")  

2. **Configure Symbols**  
   ```bash
   # Run in WinDbg command window:
   .sympath srv*https://msdl.microsoft.com/download/symbols
   .reload /f  # Force symbol reload
   ```
   *Pro Tip:* Cache symbols locally:  
   `.sympath cache*C:\SymCache;srv*https://msdl.microsoft.com/download/symbols`

3. **Set Source Code Path** (For driver developers)  
   `.srcpath+ C:\DriverSourceCode`  

---

#### **Step 2: Loading a Crash Dump**  
1. **GUI Method**:  
   File → Open dump file → Select `.dmp` or `.mdmp`  

2. **Command Line**:  
   `windbg.exe -z C:\dumps\crash.dmp`  

3. **First Response**:  
   ```bash
   !analyze -v  # Let WinDbg perform automated analysis
   ```
   *Observe:*  
   - **BUGCHECK_CODE** (e.g., `0x133`)  
   - **FAILING_MODULE** (culprit driver)  
   - **STACK_TEXT** (call stack)  

---

#### **Step 3: Essential Commands Cheat Sheet**  
| **Command**         | **Purpose**                          | **Example**                     |
|----------------------|--------------------------------------|---------------------------------|
| `.reload /f`         | Reload symbols                       |                                 |
| `lm`                 | List loaded modules                  | `lm v m nt` (kernel details)    |
| `!thread`            | Show current thread                  | `!thread fffff8075e6d8080`      |
| `!process`           | Inspect processes                    | `!process 0 0` (all processes)  |
| `k`                  | Display call stack                   | `kb` (with params)              |
| `!irp`               | Examine I/O Request Packets          | `!irp ffffc58a1e4c6a10`         |
| `dt`                 | Dump structure                       | `dt nt!_KTHREAD`                |
| `!pool`              | Inspect memory pools                 | `!pool ffff800000000000`        |
| `.dump /m`           | Save current session as dump         | `.dump /m C:\analysis.dmp`      |

---

#### **Step 4: Real Crash Analysis Walkthrough**  
**Scenario**: BSOD with `DRIVER_IRQL_NOT_LESS_OR_EQUAL (d1)`  

1. **Initial Analysis**:  
   ```bash
   !analyze -v
   ```
   Output shows:  
   ```diff
   + FAILING_MODULE: Netwtw04.sys (WiFi driver)
   + STACK_TEXT:  
   #00 netwtw04!SomeFunction+0x2a
   ```

2. **Inspect the Faulting Thread**:  
   ```bash
   !thread  # Note thread address
   !thread ffffc58a1e4c6a10  # Replace with your thread
   ```

3. **Check Driver Version**:  
   ```bash
   lm vm netwtw04  # Verify driver version/timestamp
   ```

4. **Manual Stack Trace**:  
   ```bash
   k # For raw stack
   dps @rsp L20  # Dump stack pointers
   ```

5. **Find Memory Corruption**:  
   ```bash
   !pool ffffc58a1e4c6a10  # Check for pool corruption
   ```

---

#### **Step 5: Advanced Techniques**  
**1. Detect Memory Leaks**  
```bash
!poolused 2  # List pools by tag
!for_each_process "!poolused @#Process"  # Per-process usage
```

**2. Analyze Hung Systems** (Live Debugging)  
```bash
!running  # Show busy threads
!locks    # Detect deadlocks
```

**3. Find Handle Leaks**  
```bash
!handle 0 0  # All handles
!htrace -enable  # Trace handle creation
```

**4. Driver Verifier Integration**  
Force crash reproduction:  
```bash
verifier.exe /flags 0x01 /driver Netwtw04.sys
```

---

#### **Step 6: Automation & Scripting**  
1. **Batch Analysis**:  
   ```bash
   $$>< C:\analysis_script.txt  # Run commands from file
   ```

2. **JavaScript Automation** (WinDbg Preview):  
   ```javascript
   function analyzeAll() {
       ExecuteCommand("!analyze -v");
       LogToFile("C:\\report.txt");
   }
   ```

3. **Common Script**:  
   Save as `auto_analysis.js`:  
   ```javascript
   function run() {
       host.namespace.Debugger.Utility.ExecuteCommand("!analyze -v");
   }
   ```

---

#### **Step 7: Pro Tips & Pitfalls**  
✅ **Must-Know Shortcuts**:  
- `F6`: Command history  
- `Ctrl+Break`: Halt debugger during long operations  
- `Ctrl+Alt+V`: Toggle verbose mode  

❌ **Avoid These Mistakes**:  
- Forgetting `.reload` after setting symbols  
- Ignoring `Parameter1` in stop code documentation  
- Misinterpreting `ntoskrnl.exe` as root cause (usually victim)  

🔧 **When !analyze Fails**:  
1. Check stack consistency with `k`  
2. Cross-reference with Event Viewer (`Event ID 41`)  
3. Verify hardware with `!sysinfo cpuinfo` + `!sysinfo smbios`  

---

#### **Sample Crash Lab**  
1. **Induce Crash**:  
   Download [NotMyFault](https://learn.microsoft.com/sysinternals) →  
   `notmyfault.exe /crash`  

2. **Analyze Generated Dump**:  
   ```bash
   !analyze -v
   lm vm myfault  # Verify buggy driver
   ```

---

#### **Resources**  
- [Microsoft Symbol Server](https://docs.microsoft.com/windows-hardware/drivers/debugger/microsoft-public-symbols)  
- [WinDbg Command Reference](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugger-commands)  
- [Common Bug Check Codes](https://www.nirsoft.net/kernel_struct/vista/BUG_CHECK_CODES.html)  

