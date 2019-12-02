#include "inputParser.hpp"
#include <vector>
#include <iostream>

using namespace std;

#define OP_ADD 1
#define OP_MUL 2
#define OP_EXT 99

int main()
{
    vector<int> values;
    inPa::inputParser::get("C:\\data\\aoc2019\\input\\day2.txt", values, ',');

   int pos = 0;

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

      // for (auto iter = values.begin(); iter != values.end(); iter +=4) {
      //    cout << "Value : " << *iter <<", " <<*(iter+1) <<", " <<*(iter+2) <<", " <<*(iter+3) <<endl;
      // }

      pos += 4;
      opCode = values[pos];
      input1 = values[pos + 1];
      input2 = values[pos + 2];
      output = values[pos + 3];
   }
}
