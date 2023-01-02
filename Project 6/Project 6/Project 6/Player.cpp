//
//  Player.cpp
//  Project 6



#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mPriorRunningTotal(0), mRunningTotal(0), mScore( 0 )
    {
        
    }
    
    void Player::roll( Die d1, Die d2 )
    {
        // cheating...
        mDie1 = d1;
        mDie2 = d2;
    }

    void Player::roll( )
    {
        mDie1.roll();
        mDie2.roll();
    }
    
    Die Player::getDie1() const
    {
        return( mDie1 );
    }

    Die Player::getDie2() const
    {
        return( mDie2 );
    }
    
    // TODO: for this Player's Dies, update the running total
    void Player::addDiceToRunningTotal( )
    {
        // STEPS TO COMPLETE
        // save prior running total first...
        mPriorRunningTotal = mRunningTotal;

        // once the total hits 16, only mDie1 get added in to the running total...
        if(mRunningTotal >= 16){
            mRunningTotal += mDie1.getValue();
        }
        // otherwise, add in both dies to the running total...
        else{
            mRunningTotal += mDie1.getValue();
            mRunningTotal += mDie2.getValue();
        }
    }

    int  Player::getRunningTotal( ) const
    {
        return( mRunningTotal );
    }

    int  Player::getPriorRunningTotal( ) const
    {
        return( mPriorRunningTotal );
    }

    void Player::resetRunningTotal( )
    {
        mRunningTotal = 0;
        mPriorRunningTotal = 0;
    }

    std::string Player::whatWasRolled()
    {
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        return( s );
    }
    
    int  Player::getScore() const
    {
        return( mScore );
    }

    // TODO: update the Player's current score based on winning a turn
    void Player::wonTurn()
    {
        mScore += 1;
    }

    // TODO: update the Player's current score based on hitting 21
    void Player::won21()
    {
        mScore += 2;
    }

}

