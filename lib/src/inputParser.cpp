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

void inputParser::get(std::string filePath, std::vector<std::vector<std::string>> &data, const char delim) {
    string line;
    ifstream file(filePath);
    if (file.is_open()) {
         while (getline(file, line)) {
            if (delim == '\0') {
               data.push_back(std::vector<std::string>());
               data.back().push_back(line);
            } else {
               stringstream lStream(line);
               data.push_back(std::vector<std::string>());
               while (lStream.good()) {
                  string subStr;
                  getline(lStream, subStr, delim);
                  data.back().push_back(subStr);
               }
            }
         }
      file.close();
   } else {
      throw "Coudln't open file " + filePath;
   }
   
}


void inputParser::get(std::string filePath, std::vector<std::string> &data, const char delim) {
    string line;
    ifstream file(filePath);
    if (file.is_open()) {
       if (delim == '\0') {
            while (getline(file, line)) {
               data.push_back(line);
            }
       } else {
            stringstream lStream(line);
            while (lStream.good()) {
               string subStr;
               getline(lStream, subStr, delim);
               data.push_back(subStr);
            }
       }
        file.close();
    } else {
        throw "Coudln't open file " + filePath;
    }

}

void inputParser::get(std::string filePath, std::vector<int> &data, const char delim) {
    string line;
    int value;
    ifstream file(filePath);
    if (file.is_open()) {
        while (getline(file, line)) {
           if (delim != '\0') {
              stringstream lStream(line);
              while (lStream.good()) {
                  string subStr;
                  getline(lStream, subStr, delim);
                  stringstream convert(subStr);
                  if (convert >> value) {
                     data.push_back(value);
                  } else {
                     throw "Could not convert string to int";
                  }
              }
           } else {
               stringstream convert(line);
               if (convert >> value) {
                  data.push_back(value);
               }
               else {
                  throw "Could not convert string to int";
               }
           }
            
            
            
        }
        file.close();
    }
    else {
        throw "Coudln't open file " + filePath;
    }
}
