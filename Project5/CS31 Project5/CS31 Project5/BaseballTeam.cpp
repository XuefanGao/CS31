//
//  BaseballTeam.cpp
//  CS31 Project5
//  Xuefan Gao
//  205555927

#include "BaseballTeam.h"
BaseballTeam::BaseballTeam(){
    mName = "";
    mHomeWins = 0;
    mHomeLosses = 0;
    mRoadWins = 0;
    mRoadLosses = 0;
}
BaseballTeam::BaseballTeam(string name){
    mName = name;
    mHomeWins = 0;
    mHomeLosses = 0;
    mRoadWins = 0;
    mRoadLosses = 0;
}

//accessors & mutators
void BaseballTeam::setName(string name){
    mName = name;
}
string BaseballTeam::getName(){
    return mName;
}
int BaseballTeam::getHomeWins(){
    return mHomeWins;
}
void BaseballTeam::setHomeWins(int wins){
    mHomeWins = wins;
}
int BaseballTeam::getHomeLosses(){
    return mHomeLosses;
}
void BaseballTeam::setHomeLosses(int losses){
    mHomeLosses = losses;
}
int BaseballTeam::getAwayWins(){
    return mRoadWins;
}
void BaseballTeam::setAwayWins(int wins){
    mRoadWins = wins;
}
int BaseballTeam::getAwayLosses(){
    return mRoadLosses;
}
void BaseballTeam::setAwayLosses(int losses){
    mRoadLosses = losses;
}


void BaseballTeam::wonHomeGame(){
    mHomeWins += 1;
}
void BaseballTeam::lostHomeGame(){
    mHomeLosses += 1;
}
void BaseballTeam::wonAwayGame(){
    mRoadWins += 1;
}
void BaseballTeam::lostAwayGame(){
    mRoadLosses += 1;
}

// Wins and losses get reset to zero
void BaseballTeam::clear(){
    mHomeWins = 0;
    mHomeLosses = 0;
    mRoadWins = 0;
    mRoadLosses = 0;
}

// returns true if total wins >= total losses
bool BaseballTeam::hasWinningRecord(){
    if((mHomeWins+mRoadWins) >= (mHomeLosses+mRoadLosses))
        return true;
    return false;
}

// returns true if road wins >= road losses
bool BaseballTeam::hasWinningRoadRecord(){
    if(mRoadWins >= mRoadLosses)
        return true;
    return false;
}

// returns true if homw wins >= home losses
bool BaseballTeam::hasWinningHomeRecord(){
    if(mHomeWins >= mHomeLosses)
        return true;
    return false;
}

// return a string with the format "www-lll"
string BaseballTeam::overallRecord(){
    string result = "";
    int w = mHomeWins+mRoadWins;
    int l = mHomeLosses+mRoadLosses;
    if(w < 10){
        result.append("00");
    }
    else if (w < 100){
        result.append("0");
    }
    
    string win = to_string(w);
    string lose = to_string(l);
    result.append(win);
    result.append("-");
    
    if(l < 10){
        result.append("00");
    }
    else if (l < 100){
        result.append("0");
    }
    result.append(lose);
    return result;
}
