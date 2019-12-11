#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include "intCode.hpp"
#include <algorithm>

using namespace std;

int main()
{
   vector<int> values;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day7.txt", values, ',');
   
   IC ic[5];
   for (int i=0; i<5; ++i)
      ic[i].load(values);

   vector<int> out;
   int permutations = 5*4*3*2*1;
   int currentPermutation = 0;

   int testValues[] = {0, 1, 2, 3, 4};
   int *const tV = testValues + sizeof(testValues) / sizeof(*testValues);
   int input[] = {0, 0};

   vector<int> pipelineOutput;

   do {
      ++currentPermutation;
      out.clear();
      out.push_back(0);
      for (int i=0; i<5; ++i) {
         input[0] = testValues[i];
         input[1] = out.back();
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
