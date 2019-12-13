#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include "intCode.hpp"
#include <algorithm>
#include "7.hpp"

using namespace std;

int main()
{
   // Day7::solution();


   vector<int> values;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day7_test2.txt", values, ',');
   
   IC ic[5];
   for (int i=0; i<5; ++i)
      ic[i].load(values);

   vector<int> out;
   int permutations = 5*4*3*2*1;
   int currentPermutation = 0;

   int testValues[] = {0, 1, 2, 3, 4};
   int *const tV = testValues + sizeof(testValues) / sizeof(*testValues);
   vector<int> input;

   vector<int> pipelineOutput;

   do {
      ++currentPermutation;
      out.clear();
      out.push_back(0);
      for (int i=0; i<5; ++i) {
         input.clear();
         input.push_back(testValues[i]);
         input.push_back(out.back());
         ic[i].run(input, out);
      }
      pipelineOutput.push_back(out.back());
      // cout << "Done Percentage: " <<setfill('0') <<setw(3) << currentPermutation * 100/permutations  <<"%" <<endl;
   } while (next_permutation(testValues, tV));  

   auto v = max_element(pipelineOutput.begin(), pipelineOutput.end());
   cout << "Output: " <<*v <<endl;

   return 0;
}

//272368 to low
//Part 2 solution: 19741286