#include "inputParser.hpp"
#include <vector>
#include <iostream>

using namespace std;

#define OP_ADD 1
#define OP_MUL 2
#define OP_EXT 99

int main()
{
    vector<int> defaultValues;
    inPa::inputParser::get("C:\\data\\aoc2019\\input\\day2.txt", defaultValues, ',');

   int opCode = defaultValues[0];
   int input1 = defaultValues[1];
   int input2 = defaultValues[2];
   int output = defaultValues[3];

   for(int noun = 0; noun < 100; ++noun) {
      for (int verb = 0; verb < 100; ++verb) {
         int pos = 0;

         vector<int> values(defaultValues);
         values[1] = noun;
         values[2] = verb;
         
         int opCode = values[0];
         int input1 = values[1];
         int input2 = values[2];
         int output = values[3];


         while (opCode != OP_EXT) {
            if (opCode == OP_ADD) {
               values[output] = values[input1] + values[input2];
            } else if (opCode == OP_MUL) {
               values[output] = values[input1] * values[input2];
            }

            pos += 4;
            opCode = values[pos];
            input1 = values[pos + 1];
            input2 = values[pos + 2];
            output = values[pos + 3];

            if (values[0] == 19690720) {
               int result = 100 * noun + verb;
               cout << "Result: " <<result <<endl;
            }
         }
      }
   }
//Todo add runtime measurements
}
