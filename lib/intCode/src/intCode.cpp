#include "intCode.hpp"
#include <sstream>

using namespace std;

IntCode::IntCode() {
   pc = 0;
   opCode = 0;
   in1 = 0;
   in2 = 0;
   input = 0;
   output = 0;
}

void IntCode::evalModes(int &opCode, int &out1, int &out2, int *target) 
{
            //10s + 1s
   opCode = ((memory[pc] / 10) % 10) + (memory[pc] % 10);

   string sStream = to_string(memory[pc] / 100);
   char out[2] = {'x', 'x'};

   for (int i=0; i<sStream.size(); ++i) {
      out[sStream.size()-1-i] = sStream.at(i);
   }

   out1 = memory[pc+1];
   out2 = memory[pc+2];
   //target = &memory[pc+3];

   if (out[0] == '0') {
      out1 = memory[out1];
   }
   if (out[1] == '0') {
      out2 = memory[out2];
   }
}

void IntCode::loadProgram(const std::vector<int> &program) {
   copy(program.begin(), program.end(), back_inserter(memory));
}

int IntCode::run(const int &input, vector<int> &output) {
   opCode = 100;
   pc = 0;

   while(opCode != OP_EXT) {
      evalModes(opCode, in1, in2, target);

      if (opCode == OP_ADD) {
         memory[memory[pc+3]] = in1 + in2;
         pc += 4;
      } else if (opCode == OP_MUL) {
         memory[memory[pc+3]] = in1 * in2;
         pc +=4;
      } else if (opCode == OP_INP) {
         memory[in1] = input;
         pc += 2;
      } else if (opCode == OP_OUT) {
         output.push_back(memory[in1]);
         pc += 2;
      } else if (opCode == OP_JIT) {
         if (in1 != 0) {
            pc = in2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_JIF) {
         if (in1 == 0) {
            pc = in2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_LTH) {
         if (in1 < in2) {
            memory[memory[pc+3]] = 1;
         } else {
            memory[memory[pc+3]] = 0;
         }
         pc += 4;
      } else if (opCode == OP_EQU) {
         if (in1 == in2) {
             memory[memory[pc+3]] = 1;
         } else {
             memory[memory[pc+3]] = 0;
         }
         pc += 4;
      } else {
         //never reach  here
         throw string("OPCode unregognized: " + opCode);
         break;
      }
   }
}


// int IntCode::add(const int &input1, const int &input2, int &target) {
//     return input1 + input2;
// }

// int IntCode::mul(const int &input1, const int &input2, int &target) {
//     return input1 + input2;
// }

// int IntCode::exit(void) {
//     return 0;
// }
