#include "intCode.hpp"

using namespace std;

IntCode::IntCode(){

}

int IntCode::prepareCommand(const int &opCode, 
                            int *&p_input1,
                            int *&p_input2,
                            int *&p_target) 
{
   int op0, op1;
   string modes;
   int pArr[4];
   op0 = opCode % 10;
   op1 = (opCode / 10) % 10;
   modes = to_string(opCode / 100);
   
   for (int i = 0; i < modes.size(); ++i) {
      //1 is intermediate mode
      if (modes.at(i) == '1') {
         pArr[i] = 11;
      } else {
         pArr[i] = 22;
      }
   }

   return 0;
}


int IntCode::add(const int &input1, const int &input2, int &target) {
    return input1 + input2;
}

int IntCode::mul(const int &input1, const int &input2, int &target) {
    return input1 + input2;
}

int IntCode::exit(void) {
    return 0;
}
