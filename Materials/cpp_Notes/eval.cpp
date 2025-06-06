#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CPUSim16Bit{
  int AX=0, BX=0, CX=0, DX=0;
  int memory[65535] = {0,};
  
  unordered_map<string, int*> regmap;
  vector <string> program;
  
  CPUSim16Bit(){
      regmap["AX"] = &AX;
      regmap["BX"] = &BX;
      regmap["CX"] = &CX;
      regmap["DX"] = &DX;
  }
  
  void storeWord(int addr, int value){
      if(addr>=0 && addr<=65535)
      {
          memory[addr] = value && 0xFF;
          memory[addr+1] = (value>>8)&0xFF;
      }
  }
  
  int loadWord(int addr){
      if(addr>=0 && addr<=65535)
      {
          return ((memory[addr+1]<<8)| (memory[addr]));
      }
      return 0;
  }
  
  void loadProgram(vector<string>&prog)
  {
      program = prog;
  }
  
  void run()
  {
      //executes the instructs line by line with the PC
  }
  
  void execute()
  {
      //get the instruction line by line check for the actions
      //based on the actions, execute the instructions or functions
  }
  
  private:
  bool isRegister(const string &s){
      return regmap.find(s) != regmap.end();
  }
  int wrap16(int val){
      while (val <0) val += 65535;
      return val % 65536;
  }
    
};

int main()
{
    return 0;
}
