//
//  TurnEvaluator.cpp
//  Project 6


#include "TurnEvaluator.h"

namespace cs31
{

TurnEvaluator::TurnEvaluator( Player human, Player computer )
{
    mHumanTotal = human.getRunningTotal();
    mComputerTotal = computer.getRunningTotal();
    mComputerPriorRunningTotal = computer.getPriorRunningTotal();
}

// TODO: complete evaluateTurn( )
// based on the player totals saved by the constructor call,
// determine which possibility has occurred



TurnEvaluator::POSSIBILITIES TurnEvaluator::evaluateTurn( ) const
{
    //POSSIBILITIES result = NOONEWON;
    // both players had blackjack
    if(mHumanTotal == 21 && mComputerTotal == 21)
        return BOTHHAVEBLACKJACK;
    // human player has blackjack (by having a score of exactly 21)
    else if(mHumanTotal == 21)
        return HUMANBLACKJACK;
    // computer player has blackjack (by having a score of exactly 21)
    else if(mComputerTotal == 21)
        return COMPUTERBLACKJACK;
    if(mHumanTotal == mComputerTotal)
           return NOONEWON;
    // human player busted (by having a score over 21)
    if(mHumanTotal > 21){
        return HUMANBUSTED;
    }
    // computer player busted (by having score over 21)
    if(mComputerTotal > 21){
        return COMPUTERBUSTED;
    }
    
    // human player won (by having a greater running total
    if(mHumanTotal > mComputerTotal)
        return HUMANWON;
    // computer player won (by having a greater running total
    else if(mComputerTotal > mHumanTotal)
        return COMPUTERWON;
    // neither player won (because they each had identical non-blackjack running totals)
    return NOONEWON;
}

// should the computer keep playing?
bool TurnEvaluator::determineComputerStrategy() const
{
    bool result = true;
    // if human busted, don't bust yourself
    if (mHumanTotal > 21)
        result = false;
    // stop if the computer has won!
    if (mComputerPriorRunningTotal > mHumanTotal)
        result = false;
    // stop once you 17 or more
    if (mComputerTotal > 17)
        result = false;
    return( result );

}

}

