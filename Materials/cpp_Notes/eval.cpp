#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

class CPU16BitSim {
    int AX = 0, BX = 0, CX = 0, DX = 0;
    int memory[65536] = {0};  // 64KB of memory
    int PC = 0;
    bool halted = false;

    unordered_map<string, int*> regMap;
    vector<string> program;

public:
    CPU16BitSim() {
        regMap["AX"] = &AX;
        regMap["BX"] = &BX;
        regMap["CX"] = &CX;
        regMap["DX"] = &DX;
    }

    void storeWord(int addr, int value) {
        if (addr >= 0 && addr < 65535) {
            memory[addr] = value & 0xFF;
            memory[addr + 1] = (value >> 8) & 0xFF;
        }
    }

    int loadWord(int addr) {
        if (addr >= 0 && addr < 65535) {
            return (memory[addr + 1] << 8) | memory[addr];
        }
        return 0;
    }

    void loadProgram(const vector<string>& prog) {
        program = prog;
        PC = 0;
        halted = false;
    }

    void run() {
        int programSize = program.size();
        while (!halted && PC >= 0 && PC < programSize) {
            execute(program[PC]);
        }
    }

    void execute(const string& instr) {
        string line = instr;
        line.erase(remove(line.begin(), line.end(), ','), line.end());

        size_t eqPos = line.find('=');
        if (eqPos != string::npos) {
            string lhs = trim(line.substr(0, eqPos));
            string rhs = trim(line.substr(eqPos + 1));

            if (isMemory(lhs)) {
                int addr = extractAddress(lhs);
                int val = evaluate(rhs);
                storeWord(addr, wrap16(val));
            } else if (isRegister(lhs)) {
                *regMap[lhs] = wrap16(evaluate(rhs));
            }

            PC++;
            return;
        }

        stringstream ss(line);
        string opcode, op1, op2;
        ss >> opcode >> op1 >> op2;

        if (opcode == "MOV") {
            if (isMemory(op1)) {
                int addr = extractAddress(op1);
                int val = isRegister(op2) ? *regMap[op2] : stoi(op2);
                storeWord(addr, wrap16(val));
            } else if (isRegister(op1)) {
                if (isMemory(op2)) {
                    *regMap[op1] = wrap16(loadWord(extractAddress(op2)));
                } else {
                    *regMap[op1] = wrap16(isRegister(op2) ? *regMap[op2] : stoi(op2));
                }
            }
            PC++;
        }
        else if (opcode == "HLT") {
            halted = true;
        }
        else {
            cout << "Invalid instruction: " << instr << "\n";
            halted = true;
        }
    }

    void dumpRegisters() {
        cout << "\n=== 🧠 16-bit CPU Register Dump ===\n";
        cout << "AX = " << setw(5) << AX << "\n";
        cout << "BX = " << setw(5) << BX << "\n";
        cout << "CX = " << setw(5) << CX << "\n";
        cout << "DX = " << setw(5) << DX << "\n";
        cout << "PC = " << setw(5) << PC << "\n";
    }

    void dumpMemory(int start, int end) {
        cout << "\n=== 🧮 Memory Dump [" << start << " to " << end << "] ===\n";
        for (int i = start; i <= end; i++) {
            cout << "mem[" << setw(5) << i << "] = " << setw(5) << memory[i] << "\n";
        }
    }

private:
    bool isRegister(const string& s) {
        return regMap.find(s) != regMap.end();
    }

    bool isMemory(const string& s) {
        return s.size() >= 3 && s.front() == '[' && s.back() == ']';
    }

    int extractAddress(const string& s) {
        return stoi(s.substr(1, s.size() - 2));
    }

    int evaluate(const string& expr) {
        stringstream ss(expr);
        string tok1, op, tok2;
        ss >> tok1 >> op >> tok2;

        int val1 = isRegister(tok1) ? *regMap[tok1] : stoi(tok1);
        if (op.empty()) return val1;

        int val2 = isRegister(tok2) ? *regMap[tok2] : stoi(tok2);
        if (op == "+") return val1 + val2;
        if (op == "-") return val1 - val2;

        return val1;
    }

    int wrap16(int val) {
        while (val < 0) val += 65536;
        return val % 65536;
    }

    string trim(const string& s) {
        size_t start = s.find_first_not_of(" \t");
        size_t end = s.find_last_not_of(" \t");
        return (start == string::npos) ? "" : s.substr(start, end - start + 1);
    }
};

int main() {
    CPU16BitSim cpu;

    vector<string> program;
    ifstream fin("program.txt");
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) program.push_back(line);
    }
    fin.close();

    cpu.loadProgram(program);
    cpu.run();

    ofstream fout("output.txt");
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());

    cpu.dumpRegisters();
    cpu.dumpMemory(0, 11);

    cout.rdbuf(coutbuf);
    cout << "✅ Execution complete. See results in output.txt\n";
    return 0;
}
