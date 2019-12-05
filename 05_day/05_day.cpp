#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include "intCode.hpp"

using namespace std;

#define OP_ADD 1
#define OP_MUL 2
#define OP_EXT 99

int main()
{
   //  vector<int> values;
   //  inPa::inputParser::get("C:\\data\\aoc2019\\input\\day5.txt", values, ',');

   vector<int> values = {3352, 4, 3, 4, 33};

   //parse opcode
   int opCode = values[0] % 1100;
   int fResult = 80;

   int modes = values[0] / 100;

   IntCode intCode;

   int *p_input1;
   int *p_input2;
   int *p_target;

   intCode.prepareCommand(values[0], p_input1, p_input2, p_target);




}
