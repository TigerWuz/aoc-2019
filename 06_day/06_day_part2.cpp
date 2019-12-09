#include "inputParser.hpp"
#include <map>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef struct Node {
   string   name;
   Node     *parent;
   vector<struct Node *> children;
};

Node *newNode(string name) {
   Node *n = new Node();
   n->name = name;
   return n;
}


int main() {

   vector<vector<string>> x;
   inPa::inputParser::get("C:\\data\\aoc2019\\input\\day6.txt", x, ')');

   list<vector<string>> values;
   values.insert(values.begin(), x.begin(), x.end());
   //for this solution to work the "COM" mut be added into the map as first element



   //values.erase(values.begin());
   Node *root = new Node();
   root->name = values.begin()->at(0);
   
   queue <Node *> qu;
   qu.push(root);
   Node *current;

   Node *santa;
   Node *you;

   while (!qu.empty()) {
      current = qu.front();
      auto it = values.begin();
      while (it != values.end()) {
         if (it->at(0) == current->name) {
            Node *child = new Node();
            child->name = it->at(1);
            child->parent = current;
            current->children.push_back(child);
            it = values.erase(it);
            qu.push(child);

            if (child->name == "YOU") {
               you = child;
            } else if (child->name == "SAN") {
               santa = child;
            }

         } else {
            ++it;
         }
      }
      qu.pop();
   }

   //my Path
   Node *cP = you;
   vector<string> myPath, santaPath;

   while (cP->parent->name != "COM") {
      myPath.push_back(cP->parent->name);
      cP = cP->parent;
   }

   //santas Path
   cP = santa;
   while (cP->parent->name != "COM") {
      santaPath.push_back(cP->parent->name);
      cP = cP->parent;
   }

   int myDistance = 0;
   int santaDistance = 0;
   bool exit = false;

   for (auto mD: myPath) {
      santaDistance = 0;
      for (auto sD: santaPath) {
         ++santaDistance;
         if (mD == sD) {
            //common point found
            exit = true;
            break;
         }
      }
      ++myDistance;

      if (exit == true) {
         break;
      }
   }

   int distance = myDistance + santaDistance -2;
   cout <<"Distance to common point: " <<distance <<endl;
}
