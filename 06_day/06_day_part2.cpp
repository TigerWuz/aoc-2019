#include "inputParser.hpp"
#include <map>
#include <iostream>

using namespace std;

// 1439 to low

int main() {

   map<string, int> orbitalMap;
   
   vector<vector<string>> values;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day6.txt", values, ')');

   //for this solution to work the "COM" mut be added into the map as first element

   orbitalMap.insert(pair<string,int>(values[0][0], 0));
   //values.erase(values.begin());

   int i = 0;
   while (values.size() != 0) {
      auto center = orbitalMap.find(values[i][0]);
      if (center == orbitalMap.end() ) {
         // we do not know the root planet until now
         //currently this is dangereous!
         ++i;
         continue;
      }
      orbitalMap.insert(pair<string,int>(values[i][1], center->second +1));
      values.erase(values.begin() + i);
      i = 0;
   }

   int orbitalSum = 0;
   for (auto &p : orbitalMap) {
      orbitalSum += p.second;
   }

   // for (auto l : values) {

   // }

   cout << "Orbit Sum: "<<orbitalSum <<endl;
   return 0;
}
