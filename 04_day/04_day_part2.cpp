#include <numeric>
#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
   //input 387638-919123
   // list<int> input(919123-387638);
   int size = 919123-387638;
   list<int> input(size+1);
   iota(input.begin(), input.end(), 387638);

   //  list<int> input = {111223, 115544, 112233, 444556};

   vector<int> output;

   int percentage = 0;
   int current = 0;

   bool next = false;

   for(auto number: input) {
      percentage = (current++) * 100 / input.size();

      vector<int> group;

      next = false;
      //check rules
      //adjacent digits
      string stringDigit = to_string(number);
      char curVal = 'X';
      for (int i = 0; i < 5; ++i) {
         if (stringDigit[i] == stringDigit[i+1]) {
            if (stringDigit[i] != curVal) {
               curVal = stringDigit[i];
               group.push_back(1);
            } else {
               group.back() += 1;
            }
         }
      }

      //count groups
      for (auto g: group) {
         if (g  == 1) {
            next = true;
         }
      }

      if (next == false) {
         continue;
      }

      for (int i = 0; i < 5; ++i) {
         if (stringDigit[i] > stringDigit[i+1]) {
            next = false;
            break;
         }
      }

      //A valid input was found
      if (next == true) {
         output.push_back(number);
      }
   }

   //Result
   cout << "Amount of possible PWs: " <<output.size() <<endl;


   return 0;
}
