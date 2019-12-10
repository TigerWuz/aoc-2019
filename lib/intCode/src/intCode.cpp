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

void IntCode::evalModes(int &out1, int &out2, int *target) 
{
   //assuming immediate mode here
   out1 = memory[pc+1];
   out2 = memory[pc+2];

   if (memory[pc] >= 100) {

      string sStream = to_string(memory[pc] / 100);
      char out[2] = {'x', 'x'};

      for (int i=0; i<sStream.size(); ++i) {
         out[sStream.size()-1-i] = sStream.at(i);
      }
      //target = &memory[pc+3];

      if (out[0] == '0') {
         out1 = memory[out1];
      }
      if (out[1] == '0') {
         out2 = memory[out2];
      }
    } else {
       // shortcut as all parameters are here in parameter mode
       out1 = memory[out1];
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
      opCode = ((memory[pc] / 10) % 10) + (memory[pc] % 10);

      if (opCode == OP_ADD) {
         evalModes(in1, in2, target);
         memory[memory[pc+3]] = in1 + in2;
         pc += 4;
      } else if (opCode == OP_MUL) {
         evalModes(in1, in2, target);
         memory[memory[pc+3]] = in1 * in2;
         pc +=4;
      } else if (opCode == OP_INP) {
         //evalModes(in1, in2, target);
         memory[memory[pc+1]] = input;
         pc += 2;
      } else if (opCode == OP_OUT) {
         //evalModes(in1, in2, target);
         output.push_back(memory[memory[pc+1]]);
         pc += 2;
      } else if (opCode == OP_JIT) {
         evalModes(in1, in2, target);
         if (in1 != 0) {
            pc = in2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_JIF) {
         evalModes(in1, in2, target);
         if (in1 == 0) {
            pc = in2;
         } else {
            pc += 3;
         }
      } else if (opCode == OP_LTH) {
         evalModes(in1, in2, target);
         if (in1 < in2) {
            memory[memory[pc+3]] = 1;
         } else {
            memory[memory[pc+3]] = 0;
         }
         pc += 4;
      } else if (opCode == OP_EQU) {
         evalModes(in1, in2, target);
         if (in1 == in2) {
             memory[memory[pc+3]] = 1;
         } else {
             memory[memory[pc+3]] = 0;
         }
         pc += 4;
      } else if (opCode == OP_EXT){
         //do nothing else
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
