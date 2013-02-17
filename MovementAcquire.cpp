/*=========================================================================
  MovementAcquire.cpp

    * Bridge Game Movement:  Acquire data for Mitchell Movement
    * Version 0.5

  Thomas M. Eidson
  February, 2013

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include "MovementAcquire.h"

// ========================

MovementAcquire::MovementAcquire(struct movement *move)
{
// ------------------------
//  Setup 
// ------------------------
  Error = false;
  Move = move;
  Move->movement_error = ACBLSP_MOVEMENT_ERROR_NOT_READY;

  arraySize = ACBLSP_MOVEMENT_MAX_ARRAY_SIZE;
  tableMax = ACBLSP_MOVEMENT_NTABLES_INDIVIDUAL_MAX;
  roundMax = ACBLSP_MOVEMENT_NROUNDS_INDIVIDUAL_MAX;
  lineMax  = 5;

  if (Move->movement_game_type != MITCHELL)
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_GAME_TYPE_NOT_MITCHELL;
    return;
  }
  if (Move->movement_is_one_winner != ONE_WINNER)
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_ONE_WINNER_NOT_MITCHELL;
    return;
  }
  if (Move->movement_is_barometer != BAROMETER)
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_BAROMETER_NOT_MITCHELL;
    return;
  }

// ------------------------
// Initialize Movement Array

  for(int i=0; i<arraySize ; i++)
  {
    Move->movement_array[i] = 0;
  }
}
MovementAcquire::~MovementAcquire()
{
  delete detail;
}

// ------------------------
// Compute Mitchell Detail
// ------------------------
void MovementAcquire::computeMitchell()
{
// Setup Mitchell Computation Object

  detail = new MitchellDetail(Move);
  Error = detail->testError();

// Compute Mitchell Movement

  if (!Error)
  {
    detail->create();

    Error = detail->testError();
    if (!Error)
    {
      Boardset   = detail->getBoardset();
      AnchorPair = detail->getAnchorPair();
      MovePair   = detail->getMovePair();
    }
  }
}

// ------------------------
//  Retrieve Detail
// ------------------------
void MovementAcquire::createMovement()
{
  int tr     = 0;
  int board1 = -1;
  int boardset   = -1;
  int anchorPair = -1;
  int movePair   = -1;
// ........................

  for(int t=0; t< Move->movement_ntables; t++)
  {
    for(int r=0; r< Move->movement_nrounds; r++)
    {
      boardset = Boardset[t][r];
      board1 = (boardset-1) * Move->movement_nboards_per_round + 1;
      anchorPair = AnchorPair[t];
      movePair   = MovePair[t][r];

      tr = t*(roundMax * lineMax) + r*lineMax;
      Move->movement_array[tr]   = anchorPair;
      Move->movement_array[tr+1] = movePair;
      Move->movement_array[tr+2] = board1;
    }
  }
  Move->movement_error = ACBLSP_MOVEMENT_ERROR_READY;
}
// ------------------------
//  Utility Methods
// ------------------------
bool MovementAcquire::testError()
{
  return Error;
}
// ======================== ========================
