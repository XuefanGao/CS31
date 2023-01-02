//
//  main.cpp
//  CS31 Project5
//  Xuefan Gao
//  205555927

#include "League.h"
#include <cassert>
#include <iostream>

int main() {
    
      BaseballTeam dodgers("LA Dodgers");
      BaseballTeam padres("SD Padres");
      BaseballTeam giants("SF Giants");

      League nlWest("National League West");
      nlWest.season(dodgers, 20, 10, 20, 10);
      nlWest.season(padres, 30, 0, 0, 30);
      nlWest.season(giants, 10, 20, 10, 20);
      assert(nlWest.mostOverallLosses(dodgers, padres, giants).getName() == "SF Giants");
      cout << "all tests passed!" << endl;
    return 0;
}
