#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "intCode.hpp"

using namespace std;

#define OP_ADD 1
#define OP_MUL 2
#define OP_INP 3
#define OP_OUT 4
#define OP_JIT 5
#define OP_JIF 6
#define OP_LTH 7
#define OP_EQU 8
#define OP_EXT 99

void getModes(const string &input, int (&out)[2]) {
   for (int i = 0; i<input.size(); ++i) {
      out[input.size() - 1 - i ] = input.at(i) - '0';
   }
}

int main()
{
   vector<int> values;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day5.txt", values, ',');

   //vector<int> values = {3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31, 
                     // 1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,
                     // 999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99};

   IntCode iC;

   iC.loadProgram(values);
   vector<int> opt;

   iC.run(5, opt);

   //vector<int> values = {3352, 4, 3, 4, 33};

   //parse opcode
   int pc = 0;
   int manualInput = 5;

   int opCode = (values[pc] % 10) + ((values[pc] / 10) %10) ;
   int modes[2] = {0,0};
   int m;
   int inp1;
   int inp2;
   int target;
   string mode;
   stringstream ss;

   while(1) {
      opCode = (values[pc] % 10) + (((values[pc] / 10) %10) * 10) ;
      m = values[pc] / 100;
      //ss << (m);
      //mode = ss.str();
      mode = to_string(m);
      modes[0] = 0;
      modes[1] = 0;

      if (opCode == OP_ADD) {
         getModes(mode, modes);
         inp1 = values[pc+1];
         inp2 = values[pc+2];
         target = values[pc+3];
         if (modes[0] == 0) {  
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = values[inp2];
         }

         values[target] = inp1 + inp2;
         pc += 4;
      } else if (opCode == OP_MUL) {
         getModes(mode, modes);
         inp1 = values[pc+1];
         inp2 = values[pc+2];
         target = values[pc+3];
         if (modes[0] == 0) {  
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = values[inp2];
         }

         values[target] = inp1 * inp2;
         pc +=4;
      } else if (opCode == OP_INP) {
         //getModes(mode, modes);
         inp1 = values[pc+1];
         values[inp1] = manualInput;
         pc += 2;
      } else if (opCode == OP_OUT) {
         inp1 = values[pc+1];
         cout << "Op Code OUT: " <<values[inp1] <<" Address(" <<inp1 <<")" <<endl;
         pc += 2;
      } else if (opCode == OP_JIT) {
         getModes(mode, modes);
         inp1 = values[pc+1];
         inp2 = values[pc+2];
         if (modes[0] == 0) {  
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = values[inp2];
         }

         if (inp1 != 0) {
            pc = inp2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_JIF) {
         getModes(mode, modes);

         inp1 = values[pc+1];
         inp2 = values[pc+2];
         if (modes[0] == 0) {  
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {  
            inp2 = values[inp2];
         }

         if (inp1 == 0) {
            pc = inp2;
         } else {
            pc += 3;
         }

      } else if (opCode == OP_LTH) {
         getModes(mode, modes);
         inp1 = values[pc+1];
         inp2 = values[pc+2];
         target = values[pc+3];
         if (modes[0] == 0) {
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {
            inp2 = values[inp2];
         }

         if (inp1 < inp2) {
            values[target] = 1;
         } else {
            values[target] = 0;
         }
         pc += 4;
      } else if (opCode == OP_EQU) {
         getModes(mode, modes);
         inp1 = values[pc+1];
         inp2 = values[pc+2];
         target = values[pc+3];
         if (modes[0] == 0) {
            inp1 = values[inp1];
         }
         if (modes[1] == 0) {
            inp2 = values[inp2];
         }

         if (inp1 == inp2) {
            values[target] = 1;
         } else {
            values[target] = 0;
         }
         pc += 4;

      } else if (opCode == OP_EXT) {
         break;
      } else {
         //never reach  here
         cout << "OPCode unregognized: " <<opCode <<endl;
         break;
      }

   }

   return 0;
}
