#include <string>
#include <sstream>
#include "intCode.hpp"

using namespace std;

void IC::load(const std::vector<int> program) {
   copy(program.begin(), program.end(), back_inserter(memory));
}


void IC::getModes(const string &input, int (&out)[2]) {
   for (int i = 0; i<input.size(); ++i) {
      out[input.size() - 1 - i ] = input.at(i) - '0';
   }
}

int IC::run(const int &input, vector<int> &output) {
   //parse opcode
   int pc = 0;
   int opCode = (memory[pc] % 10) + ((memory[pc] / 10) %10) ;
   int modes[2] = {0,0};
   int m;
   int inp1;
   int inp2;
   int target;
   string mode;
   stringstream ss;

   while(1) {
      opCode = (memory[pc] % 10) + (((memory[pc] / 10) %10) * 10) ;
      m = memory[pc] / 100;
      //ss << (m);
      //mode = ss.str();
      mode = to_string(m);
      modes[0] = 0;
      modes[1] = 0;

      if (opCode == OP_ADD) {
         getModes(mode, modes);
         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         target = memory[pc+3];
         if (modes[0] == 0) {  
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = memory[inp2];
         }

         memory[target] = inp1 + inp2;
         pc += 4;
      } else if (opCode == OP_MUL) {
         getModes(mode, modes);
         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         target = memory[pc+3];
         if (modes[0] == 0) {  
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = memory[inp2];
         }

         memory[target] = inp1 * inp2;
         pc +=4;
      } else if (opCode == OP_INP) {
         //getModes(mode, modes);
         inp1 = memory[pc+1];
         memory[inp1] = input;
         pc += 2;
      } else if (opCode == OP_OUT) {
         inp1 = memory[pc+1];
         output.push_back(memory[inp1]);
         //cout << "Op Code OUT: " << <<" Address(" <<inp1 <<")" <<endl;
         pc += 2;
      } else if (opCode == OP_JIT) {
         getModes(mode, modes);
         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         if (modes[0] == 0) {  
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = memory[inp2];
         }

         if (inp1 != 0) {
            pc = inp2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_JIF) {
         getModes(mode, modes);

         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         if (modes[0] == 0) {  
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = memory[inp2];
         }

         if (inp1 == 0) {
            pc = inp2;
         } else {
            pc += 3;
         }

      } else if (opCode == OP_LTH) {
         getModes(mode, modes);
         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         target = memory[pc+3];
         if (modes[0] == 0) {
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {
            inp2 = memory[inp2];
         }

         if (inp1 < inp2) {
            memory[target] = 1;
         } else {
            memory[target] = 0;
         }
         pc += 4;
      } else if (opCode == OP_EQU) {
         getModes(mode, modes);
         inp1 = memory[pc+1];
         inp2 = memory[pc+2];
         target = memory[pc+3];
         if (modes[0] == 0) {
            inp1 = memory[inp1];
         }
         if (modes[1] == 0) {
            inp2 = memory[inp2];
         }

         if (inp1 == inp2) {
            memory[target] = 1;
         } else {
            memory[target] = 0;
         }
         pc += 4;

      } else if (opCode == OP_EXT) {
         break;
      } else {
         //never reach  here
         throw "OPCode unregognized: " + opCode;
         break;
      }

   }
}
