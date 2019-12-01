#include "inputParser.hpp"
#include <vector>
#include <iostream>

using namespace std;

int fuelCalc(const int &fuel){
    int div = fuel / 3 - 2;
    if ( div > 0 ) {
        return div + fuelCalc(div);
    } else {
        return 0;
    }
}

int main()
{
    vector<int> values;
    inPa::inputParser::get("E:\\Dokumente\\AdventOfCode\\2019\\input\\day1_1.txt", values);

    int sum = 0;

    for (auto iter = values.begin(); iter != values.end(); ++iter) {
#ifdef PART_2
        sum += fuelCalc(*iter);
#else
        int div = *iter / 3 - 2;
        sum += div;
#endif
    }  

    cout <<"Fuel Requirement Sum: " <<sum <<endl;
}