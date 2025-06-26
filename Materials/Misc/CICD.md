### Comprehensive Training Guide: Git, Build/CI/CD Systems, Azure DevOps, TeamCity, Jira

---

#### **1. Introduction to Git and Git Clients**
**Why Git?**  
Version control for tracking code changes, enabling collaboration, and maintaining history.

**Key Concepts:**  
- **Repository**: Project folder with version history  
- **Commit**: Snapshot of changes  
- **Branch**: Isolated line of development  
- **Merge**: Combining branches  
- **Remote**: Cloud-hosted repository (e.g., GitHub, Azure Repos)

**Popular Git Clients:**  
| Client             | Best For                          | Key Features                          |
|--------------------|-----------------------------------|---------------------------------------|
| Git CLI            | Full control/power users          | All Git commands                      |
| VS 2022 Git Tools  | Integrated IDE workflow           | GUI for commits/branches in Solution Explorer |
| GitHub Desktop     | Beginners/visual learners         | Simplified UI, drag-and-drop merging  |
| GitKraken          | Complex workflows                 | Visual commit graph, Jira integration |

---

#### **Hands-On Exercise: Git Basics in VS 2022**
1. **Create a Repository**  
   - In VS 2022: `Git > Create Git Repository`  
   - Initialize with a README.md

2. **First Commit**  
   ```cpp
   // main.cpp
   #include <iostream>
   int main() {
     std::cout << "Hello Git!" << std::endl;
     return 0;
   }
   ```
   - Stage changes in `Git Changes` window > Commit with message "Initial commit"

3. **Branching & Merging**  
   - Create branch: `Git > New Branch > feature/calculator`  
   - Add calculator function:  
     ```cpp
     int add(int a, int b) { return a + b; }
     ```
   - Commit > Switch back to `main` > `Git > Merge Branches`

4. **Remote Setup**  
   - Create free Azure Repos (dev.azure.com)  
   - Push: `Git > Push > Publish to Azure DevOps`

---

#### **2. Build Systems & CI/CD Overview**
**Build System**: Tools compiling source code (e.g., MSBuild for C++).  
**CI/CD Pipeline**:  
- **Continuous Integration**: Automatically build/test on every commit  
- **Continuous Delivery**: Auto-deploy to test/production environments  

**Key Components:**  
- **Triggers**: Code push, scheduled builds  
- **Artifacts**: Compiled binaries/libs  
- **Environments**: Dev, Test, Production  

**Popular Tools Comparison:**  
| Tool          | Strengths                     | C++ Support          |
|---------------|-------------------------------|----------------------|
| Azure Pipelines | Cloud/on-prem, YAML pipelines | MSBuild, CMake tasks |
| TeamCity      | Powerful agents, .NET focus   | Custom build steps   |
| Jenkins       | Open-source, plugins          | Requires scripting   |

---

#### **Hands-On: Simple CI Pipeline in Azure DevOps**
1. **Create `azure-pipelines.yml`**  
   ```yaml
   trigger:
   - main  # Runs on main branch commits

   pool:
     vmImage: 'windows-2022'  # VS 2022 preinstalled

   steps:
   - task: VSBuild@1
     inputs:
       solution: '**/*.sln'
       platform: 'x64'
       configuration: 'Release'

   - task: VSTest@2
     inputs:
       platform: 'x64'
       configuration: 'Release'
   ```

2. **Setup Pipeline**  
   - Azure DevOps > Pipelines > New Pipeline  
   - Select your repository > "Existing Azure Pipelines YAML"  
   - Run pipeline on commit to see build/test results

---

#### **3. Azure DevOps Server, TeamCity, Jira Overview**
**Azure DevOps Server (On-Prem)**  
- **Services**: Repos (Git), Pipelines (CI/CD), Boards (tasks), Test Plans  
- **Use Case**: Enterprise teams needing full control  
- **C++ Workflow**:  
  ```mermaid
  graph LR
    A[Code in Azure Repos] --> B[Build with MSBuild]
    B --> C[Run Tests]
    C --> D[Deploy Artifacts]
```

**TeamCity (JetBrains)**  
- **Strengths**:  
  - Build chains (multi-stage pipelines)  
  - VCS integrations (Git, SVN)  
  - Agent pooling for parallel builds  
- **C++ Tip**: Use command-line runner for CMake/MSBuild  

**Jira (Atlassian)**  
- **Core Features**:  
  - Issue tracking (bugs, tasks)  
  - Scrum/Kanban boards  
  - Integrations (Git, CI tools)  
- **Key Terms**:  
  - **Epic**: Large feature (e.g., "Payment System")  
  - **Story**: User-facing feature ("Process credit card")  
  - **Task**: Technical work ("Implement encryption")  

---

#### **Integration Demo: Jira + Git + CI**
1. **Link Jira to Azure Repos**  
   - Jira project > Project settings > Development tools  
   - Connect repository using OAuth

2. **Reference Issues in Commits**  
   ```bash
   git commit -m "PROJ-123 Fix null pointer exception"
   ```

3. **CI Build Status in Jira**  
   - Azure Pipelines > Service hook > Jira  
   - See build status on Jira issues:  
     ![Jira build status](https://i.imgur.com/3G7TfYl.png)

---

#### **Training Tips for New Trainers**
1. **Pre-Setup**:  
   - Prepare VM with VS 2022, Git, Azure DevOps agent  
   - Use [C++ sample projects](https://github.com/microsoft/vcpkg)

2. **Common C++ Pitfalls**:  
   - Library dependencies in CI (vcpkg helps)  
   - Long build times (cache NuGet packages)  
   - Platform-specific issues (x86 vs x64)

3. **Participant Exercises**:  
   - **Git**: Resolve a merge conflict  
   - **CI**: Break build with failed test, fix it  
   - **Jira**: Create sprint backlog from user stories

4. **Resources**:  
   - [Git Cheat Sheet](https://training.github.com/)  
   - [Azure Pipelines for C++](https://aka.ms/cpp-pipelines)  
   - [TeamCity C++ Guide](https://www.jetbrains.com/help/teamcity/cpp.html)

