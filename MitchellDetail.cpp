/*=========================================================================
  MitchellDetail.cpp

    * Mitchell Movement:  
      - Compute Details of Movement
      - includes Simple:  Skip
      - missing  Simple:  ByeStand & Relay features
    * Version 0.5

  Thomas M. Eidson
  February, 2013

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include "MitchellDetail.h"
using namespace std;

// ========================

MitchellDetail::MitchellDetail(struct movement *move)
{
// ------------------------
//  Copy & Test Inputs

  Move = move;
  Move->movement_error = ACBLSP_MOVEMENT_ERROR_DETAIL_START;
  Error   = false;

  Tables = Move->movement_ntables;
  Rounds = Move->movement_nrounds;

  Boards = Move->movement_nboards_in_play;
  BoardsPerSet = Move->movement_nboards_per_round;
  BoardsPlayedMax = Move->movement_max_boards_played;
  BoardSets = Boards / BoardsPerSet;

  StartTable = Move->movement_table_board_1_starts_at;
  StartMovePair = Move->movement_ew_pair_playing_board_1;
  SkipRound = Move->movement_skip_after_this_round + 1;
  Byestand = Move->movement_bye_stand;

  if (SkipRound > 1) doSkip = true;
  else               doSkip = false;

// ------------------------
// Assume:  Phantom Pair Number > 0 implies N/S

  PhantomPair = Move->movement_phantom_pair_number;
  if (PhantomPair > 0)  PhantomNS = true;
  else
  {
    PhantomPair = abs(PhantomPair);
    PhantomNS = false;
  }

// ------------------------
// Boards & Pairs Setup

  AnchorPairs = Tables;
  MovePairs = Tables;

  Boardset   = new int*[Tables];
  MovePair   = new int*[Tables];
  for(int t=0; t<Tables; t++)
  {
    Boardset[t] = new int[Rounds];
    MovePair[t] = new int[Rounds];
  }
  AnchorPair = new int[Tables];
}

// ------------------------
MitchellDetail::~MitchellDetail()
{
  delete Boardset;
  delete AnchorPair;
  delete MovePair;
}
// ------------------------
//  Utility Methods
// ------------------------
int** MitchellDetail::getBoardset() { return Boardset; }
int*  MitchellDetail::getAnchorPair() { return AnchorPair; }
int** MitchellDetail::getMovePair() { return MovePair; }

bool MitchellDetail::testError()
{
  return Error;
}
// ------------------------
//  Primary Method:  create "struct Movement"
// ------------------------
void MitchellDetail::create()
{
  int nspair = 0;

  int boardset_start = 0;
  int boardset = 0;
  int round = 0;
  int tableOS = 0;

  int movePair_start = 0;
  int movePair = 0;
// ........................
// ------------------------
// Setup AnchorPair
// ------------------------

  nspair = 1;
  for(int t=0; t<Tables; t++)
  {
    AnchorPair[t] = nspair;
    nspair = nspair + 1;
  }

// ------------------------
// Setup Board Sets
// ------------------------

  boardset_start = 0;

  for(int r=0; r<Rounds; r++)
  {
    round = r+1;
    tableOS = StartTable;
    boardset_start = boardset_start + 1;
    boardset = boardset_start;
    
    for(int t=0; t<Tables; t++)
    {
      Boardset[tableOS-1][round-1] = boardset;
      tableOS = tableOS + 1;
      if (tableOS > Tables) tableOS = 1;
      boardset = boardset + 1;
      if (boardset > BoardSets) boardset = 1;
    }
  }
// ------------------------
// Setup MovePair
// ------------------------
    
  for(int t=0; t<Tables; t++)
  {
    if (Boardset[t][0] == 1)
    {
      StartMoveTable = t+1;
      t = Tables;
    }
  }

  movePair_start = StartMovePair + 1;
  tableOS        = StartMoveTable;

  for(int r=0; r<Rounds; r++)
  {
    round = r+1;
    tableOS = StartMoveTable;
    if ((doSkip) && (round == SkipRound))
    {
      movePair_start = movePair_start - 2;
#ifdef _DEBUG_
int mp0 = movePair_start;
#endif
      if (movePair_start == 0)       movePair_start = Tables;
      else if (movePair_start == -1) movePair_start = Tables-1;
#ifdef _DEBUG_
int mp1 = movePair_start;
cerr << "r: " << round << " mP0/1: " << mp0 << " " << mp1 << endl;
#endif
    }
    else
    {
      movePair_start = movePair_start - 1;
      if (movePair_start <= 0) movePair_start = Tables;
    }
    movePair = movePair_start;
    
    for(int t=0; t<Tables; t++)
    {
      MovePair[tableOS-1][round-1] = movePair;
      tableOS = tableOS + 1;
      if (tableOS > Tables) tableOS = 1;
      movePair = movePair + 1;
      if (movePair > MovePairs) movePair = 1;
    }
  }
  Move->movement_error = ACBLSP_MOVEMENT_ERROR_DETAIL_END;
}
