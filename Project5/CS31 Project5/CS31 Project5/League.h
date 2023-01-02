//
//  League.hpp
//  CS31 Project5
//  Xuefan Gao
//  205555927


#include <string>
#include "BaseballTeam.h"
using namespace std;

#ifndef League_hpp
#define League_hpp

class League{
public:
    League(string name);
       
    //accessors & mutators
    void setName(string name);
    string getName();
    void play(BaseballTeam &away, BaseballTeam &home, int awayScore, int homeScore);
    void season(BaseballTeam &team, int homewins, int homelosses, int roadwins, int roadlosses);
    BaseballTeam pennantWinner(BaseballTeam team1, BaseballTeam team2, BaseballTeam team3, BaseballTeam team4, BaseballTeam team5);
    BaseballTeam mostOverallLosses(BaseballTeam t1, BaseballTeam t2, BaseballTeam t3);
private:
    string mName;

};
#endif /* League_hpp */
