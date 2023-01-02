//
//  main.cpp
//  CS31 Project5
//  Xuefan Gao
//  205555927

#include "League.h"
#include <cassert>
#include <iostream>

int main() {
    
      BaseballTeam team( "Your Team" );
      assert( team.getName( ) == "Your Team" );
      assert( team.overallRecord( ) == "000-000" );
      assert( team.hasWinningRecord( ) );
      assert( team.hasWinningRoadRecord( ) );
      assert( team.hasWinningHomeRecord( ) );
      team.wonHomeGame( );
      team.lostAwayGame( );
      assert( team.overallRecord( ) == "001-001" );
      assert( team.hasWinningRecord( ) );
      assert( ! team.hasWinningRoadRecord( ) );
      assert( team.hasWinningHomeRecord( ) );
      team.clear( );
      assert( team.overallRecord( ) == "000-000" );
      League league( "Your League" );
      assert( league.getName() == "Your League" );
      league.season( team, 15, 10, 10, 15 );
      assert( team.overallRecord( ) == "025-025" );
      assert( team.hasWinningRecord( ) );
      assert( !team.hasWinningRoadRecord( ) );
      assert( team.hasWinningHomeRecord( ) );
      cout << "all tests passed!" << endl;
    return 0;
}
