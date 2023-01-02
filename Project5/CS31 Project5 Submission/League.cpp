//
//  League.cpp
//  CS31 Project5
//  Xuefan Gao
//  205555927

#include "League.h"
League::League(string name){
    mName = name;
}
    
//accessors & mutators
void League::setName(string name){
    mName = name;
}

string League::getName(){
    return mName;
}

// final game score is reported for two teams playing a game. Both team's home or away wins/losses should get updated based on that score.
void League::play(BaseballTeam &away, BaseballTeam &home, int awayScore, int homeScore){
    // if home wins
    if(homeScore > awayScore){
        home.wonHomeGame();
        away.lostAwayGame();
    }
    else{
        home.lostHomeGame();
        away.wonAwayGame();
    }
}

// report a full season's set of wins and losses. The passed team should have its home and away wins/losses should get updated based on those values.
void League::season(BaseballTeam &team, int homewins, int homelosses, int roadwins, int roadlosses){
    team.setHomeWins(homewins);
    team.setHomeLosses(homelosses);
    team.setAwayWins(roadwins);
    team.setAwayLosses(roadlosses);
}

// select the team with the best overall record from the five passed team arguments.

BaseballTeam League::pennantWinner(BaseballTeam team1, BaseballTeam team2, BaseballTeam team3, BaseballTeam team4, BaseballTeam team5){
    string r1 = team1.overallRecord();
    string r2 = team2.overallRecord();
    string r3 = team3.overallRecord();
    string r4 = team4.overallRecord();
    string r5 = team5.overallRecord();
    if(r1>=r2 && r1>=r3 && r1>=r4 && r1>=r5)
        return team1;
    else if(r2>=r1 && r2>=r3 && r2>=r4 && r2>=r5 )
        return team2;
    else if(r3>=r1 && r3>=r2 && r3>=r4 && r3>=r5 )
        return team3;
    else if(r4>=r1 && r4>=r3 && r4>=r2 && r4>=r5 )
        return team4;
    else
        return team5;
}
