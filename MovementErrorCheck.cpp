/*=========================================================================
  MovementErrorCheck.cpp

    * Bridge Game Movement:  Test Movement Structure
                             . values in correct ranges
                             . consistancy
    * Version 0.5

  Thomas M. Eidson
  February, 2013

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include "MovementErrorCheck.h"
using namespace std;

// ========================

MovementErrorCheck::MovementErrorCheck(struct movement *move)
{
// ------------------------
//  Setup
// ------------------------
  Move = move;
  Error = false;

  arraySize = ACBLSP_MOVEMENT_MAX_ARRAY_SIZE;
  tableMax = ACBLSP_MOVEMENT_NTABLES_INDIVIDUAL_MAX;
  roundMax = ACBLSP_MOVEMENT_NROUNDS_INDIVIDUAL_MAX;
  lineMax = 5;
  arrayMax = tableMax * roundMax *lineMax;

  Boards = Move->movement_nboards_in_play;
  BoardsPerSet = Move->movement_nboards_per_round;
  BoardsPlayedMax = Move->movement_max_boards_played;
}
// ------------------------
//  Primary Range Validity Tests
// ------------------------
// Need Constant for "lineMax"

void 
MovementErrorCheck::movement_error_check()
{
  int imin, imax;
  bool result;
  bool ind;

// ........................

  Move->movement_error = ACBLSP_MOVEMENT_ERROR_READY;
  ind = is_ind();

// ------------------------
// Version Validation
  result = check_is_valid
  ( Move->movement_structure_version,
    ACBLSP_STRUCTURE_VERSION_MIN,
    ACBLSP_STRUCTURE_VERSION_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_VERSION );

// ------------------------
// Data Validation

  result = check_is_valid
  ( Move->movement_function, 
    ACBLSP_MOVEMENT_FUNCTION_MIN,
    ACBLSP_MOVEMENT_FUNCTION_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_FUNCTION );

  imin = ACBLSP_MOVEMENT_NTABLES_MIN;
  if (ind) { imax = ACBLSP_MOVEMENT_NTABLES_INDIVIDUAL_MAX; }
  else     { imax = ACBLSP_MOVEMENT_NTABLES_PAIRS_MAX; }
  result = check_is_valid(Move->movement_ntables, imin, imax, 
           ACBLSP_MOVEMENT_ERROR_BAD_TABLE_NUMBER );

  result = check_is_valid
  ( Move->movement_nboards_in_play,
    ACBLSP_MOVEMENT_NBOARDS_IN_PLAY_MIN,
    ACBLSP_MOVEMENT_NBOARDS_IN_PLAY_MAX,
    ACBLSP_MOVEMENT_ERROR_BAD_BOARDS_IN_PLAY );

  imin = ACBLSP_MOVEMENT_NROUNDS_MIN;
  if (ind) { imax = ACBLSP_MOVEMENT_NROUNDS_INDIVIDUAL_MAX; }
  else     { imax = ACBLSP_MOVEMENT_NROUNDS_PAIRS_MAX; }
  result = check_is_valid(Move->movement_nrounds, imin, imax, 
           ACBLSP_MOVEMENT_ERROR_BAD_ROUND_NUMBER );

  result = check_is_valid
  ( Move->movement_nboards_per_round,
    ACBLSP_MOVEMENT_NBOARDS_PER_ROUND_MIN,
    ACBLSP_MOVEMENT_NBOARDS_PER_ROUND_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_BOARDS_PER_ROUND );

  result = check_is_valid
  ( Move->movement_max_boards_played,
    ACBLSP_MOVEMENT_MAX_BOARDS_PLAYED_MIN,
    ACBLSP_MOVEMENT_MAX_BOARDS_PLAYED_MAX,
    ACBLSP_MOVEMENT_ERROR_BAD_MAX_BOARDS_PLAYED );

  imin = ACBLSP_MOVEMENT_NROUNDS_PLAYED_MIN;
  imax = ACBLSP_MOVEMENT_NROUNDS_PLAYED_MAX;
  result = check_is_valid( Move->movement_nrounds_played, imin, imax, 
           ACBLSP_MOVEMENT_ERROR_BAD_MAX_ROUNDS_PLAYED );

  result = check_is_valid
  ( Move->movement_game_type,
    ACBLSP_MOVEMENT_GAME_TYPE_MIN,
    ACBLSP_MOVEMENT_GAME_TYPE_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_GAME_TYPE );

// NOTE:  Can't check file name

  result = check_is_valid
  ( Move->movement_table_board_1_starts_at,
    ACBLSP_MOVEMENT_TABLE_BOARD_1_STARTS_AT_MIN,
    ACBLSP_MOVEMENT_TABLE_BOARD_1_STARTS_AT_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_BOARD_1_STARTS );

  result = check_is_valid
  ( Move->movement_ew_pair_playing_board_1,
    ACBLSP_MOVEMENT_EW_PAIR_PLAYING_BOARD_1_MIN,
    ACBLSP_MOVEMENT_EW_PAIR_PLAYING_BOARD_1_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_EW_PAIR_PLAYING_BOARD_1 );

  result = check_is_valid
  ( Move->movement_skip_after_this_round,
    ACBLSP_MOVEMENT_SKIP_AFTER_THIS_ROUND_MIN,
    ACBLSP_MOVEMENT_SKIP_AFTER_THIS_ROUND_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_SKIP_AFTER_THIS_ROUND );

  result = check_is_valid( Move->movement_bye_stand,
    ACBLSP_MOVEMENT_BYE_STAND_MIN,
    ACBLSP_MOVEMENT_BYE_STAND_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_BYE_STAND );

  result = check_is_valid
  ( Move->movement_is_barometer,
    ACBLSP_MOVEMENT_IS_BAROMETER_MIN,
    ACBLSP_MOVEMENT_IS_BAROMETER_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_BAROMETER );

  result = check_is_valid
  ( Move->movement_phantom_pair_number,
    ACBLSP_MOVEMENT_PHANTOM_PAIR_NUMBER_MIN,
    ACBLSP_MOVEMENT_PHANTOM_PAIR_NUMBER_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_PHANTOM_PAIR_NUMBER );

  result = check_is_valid
  ( Move->movement_is_one_winner,
    ACBLSP_MOVEMENT_IS_ONE_WINNER_MIN,
    ACBLSP_MOVEMENT_IS_ONE_WINNER_MAX, 
    ACBLSP_MOVEMENT_ERROR_BAD_ONE_WINNER );

// NEWFIELDS - Additional range validity tests here

// Don't do consistancy test with invalid data

  if (result == false) return;

// Consistancy Test

  if ( arrayMax != arraySize )
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_INCONSISTENT_ARRAY_SIZES;
    return;
  }

  if (Boards%BoardsPerSet != 0)
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_INCONSISTANT_BOARDS;
    return;
  }
  if (Boards < BoardsPlayedMax )
  {
    Error = true;
    Move->movement_error = ACBLSP_MOVEMENT_ERROR_INSUFFICIENT_NUMBER_BOARDS;
    return;
  }

}
// ------------------------
//  Internal Toolkit
// ------------------------
//  Game Type Tests
//   Returns 1 if "is test" true , 0 otherwise

bool 
MovementErrorCheck::is_pairs()
{
  int i;
// ........................
  i = Move->movement_game_type;
  if (i == ACBLSP_MOVEMENT_GAME_TYPE_PAIRS) return true;
  return false;
}

bool 
MovementErrorCheck::is_ind()
{
  int i;
// ........................
  i = Move->movement_game_type;
  if (i == ACBLSP_MOVEMENT_GAME_TYPE_IND) return true;
  return false;
}

// ------------------------
// Check value is between the minimum and maximum allowed

bool
MovementErrorCheck::check_is_valid(int ival, int imin, int imax, int ierr)
{
  if (ival < imin)
  {
    Move->movement_error = ierr + 1;
    return false;
  }
  if (ival > imax)
  {
    Move->movement_error = ierr + 2;
    return false;
  }
  return true;
}
