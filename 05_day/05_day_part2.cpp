#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include "intCode.hpp"

using namespace std;

int main()
{
   vector<int> values;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day5.txt", values, ',');
   
   IC ic;
   ic.load(values);
   vector<int> out;

   ic.run(5, out);

   cout << "Output: " <<out.back() <<endl;

   return 0;
}
