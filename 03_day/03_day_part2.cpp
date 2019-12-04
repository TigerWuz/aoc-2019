#include "inputParser.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class Point2D {
   public:
      Point2D(int x=0, int y=0, int steps=0){
         m_x = x;
         m_y = y;
         m_steps = steps;
      };

      int m_x;
      int m_y;
      int m_steps;

      bool operator == (const Point2D &other) {
         if ((m_x == other.m_x) && (m_y == other.m_y)) {
            return true;
         } else {
            return false;
         }
      }

      bool operator < (const Point2D &right) {
         if (m_x < right.m_x) {
            return true;
         } else if (m_x == right.m_x) {
            if (m_y <= right.m_y) {
               return true;
            } else {
               return false;
            }
         } else {
            return false;
         }
      }
};

class Wire {
   public:
      vector<Point2D> m_path;

      void createPath(const vector<string> &input);
};

void Wire::createPath(const vector<string> &input) {
   Point2D currentPoint = Point2D();
   m_path.push_back(currentPoint);

   for (auto inputIter = input.begin(); inputIter != input.end(); ++inputIter) {
      stringstream stringDist(inputIter->substr(1));
      int distance = 0;
      stringDist >> distance;
      switch (inputIter->at(0)) {
         case 'R':
            for (int i=0; i < distance; ++i) {
               Point2D p = Point2D(m_path.back().m_x + 1, m_path.back().m_y, m_path.back().m_steps + 1);
               m_path.push_back(p);
            }
            break;
         case 'U':
            for (int i=0; i < distance; ++i) {
               Point2D p = Point2D(m_path.back().m_x, m_path.back().m_y + 1, m_path.back().m_steps + 1);
               m_path.push_back(p);
            }
            break;
         case 'L':
            for (int i=0; i < distance; ++i) {
               Point2D p = Point2D(m_path.back().m_x - 1, m_path.back().m_y,  m_path.back().m_steps + 1);
               m_path.push_back(p);
            }
            break;
         case 'D':
            for (int i=0; i < distance; ++i) {
               Point2D p = Point2D(m_path.back().m_x, m_path.back().m_y - 1, m_path.back().m_steps + 1);
               m_path.push_back(p);
            }
            break;
      }

   }
}


int main()
{
   vector<vector<string>> inputData;
    Wire wireOne;
    Wire wireTwo;
    inPa::inputParser::get("C:\\data\\aoc2019\\input\\day3.txt", inputData, ',');

    wireOne.createPath(inputData.at(0));
    wireTwo.createPath(inputData.at(1));

   vector<Point2D> crossings;
   vector<Point2D>::iterator st;

   for (auto iter=wireOne.m_path.begin(); iter != wireOne.m_path.end(); ++iter) {
      st = std::find(wireTwo.m_path.begin(), wireTwo.m_path.end(), *iter);
      if ( st != wireTwo.m_path.end()) {
         int steps = iter->m_steps + st->m_steps;
         crossings.push_back(Point2D(iter->m_x, iter->m_y, steps));
      }
   }

   crossings.erase(crossings.begin());
   vector<int> stepDist;
   //find nearest manhatten distance
   // for (auto iter = crossings.begin(); iter != crossings.end(); ++iter) {
      
   //    manDist.push_back(abs(iter->m_x) + abs(iter->m_y));
   // }

   int minVal = crossings.at(0).m_steps;
   for (auto iter = crossings.begin(); iter != crossings.end(); ++iter) {
      if (iter->m_steps < minVal) {
         minVal = iter->m_steps;
      }
   }

   cout << "Result Min Dist = " << minVal << endl;

}
