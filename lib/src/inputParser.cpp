#include "inputParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace inPa;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;
using std::stringstream;




void inputParser::get(std::string filePath, std::vector<std::string> &data) {
    string line;
    ifstream file(filePath);
    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
    else {
        throw "Coudln't open file " + filePath;
    }

}

void inputParser::get(std::string filePath, std::vector<int> &data) {
    string line;
    int value;
    ifstream file(filePath);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream convert(line);
            if (convert >> value) {
                data.push_back(value);
            }
            else
            {
                    throw "Could not convert string to int";
            }
            
            
        }
        file.close();
    }
    else {
        throw "Coudln't open file " + filePath;
    }
}