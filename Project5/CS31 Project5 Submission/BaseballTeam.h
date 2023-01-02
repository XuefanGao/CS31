//
//  BaseballTeam.h
//  CS31 Project5
//  Xuefan Gao
//  205555927

#include <string>
using namespace std;

#ifndef BaseballTeam_h
#define BaseballTeam_h

class BaseballTeam{
public:
    BaseballTeam();
    BaseballTeam(string name);
    
    //accessors & mutators
    void setName(string name);
    string getName();
    int getHomeWins();
    void setHomeWins(int wins);
    int getHomeLosses();
    void setHomeLosses(int wins);
    int getAwayWins();
    void setAwayWins(int wins);
    int getAwayLosses();
    void setAwayLosses(int loses);
    void wonHomeGame();
    void lostHomeGame();
    void wonAwayGame();
    void lostAwayGame();
    void clear();
    bool hasWinningRecord();
    bool hasWinningRoadRecord();
    bool hasWinningHomeRecord();
    string overallRecord();
private:
    string mName;
    int mHomeWins;
    int mHomeLosses;
    int mRoadWins;
    int mRoadLosses;

    
    
};

#endif /* BaseballTeam_hpp */
