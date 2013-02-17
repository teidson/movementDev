/*
 * Copyright 2012 Hammond Software
 *
 * Front end to test the movement code
 *
 *  movement_main.c
 *  Thomas M. Eidson
 *
 */
#include <stdio.h>
#include <string.h>
#include "inc/acblsp_movement.h"
#include "acblsp_control.h"
#include "MovementError.h"

// ========================
// MAIN

void movement_function(struct movement *);

int main()
{
  int t = -1;
  int r = -1;
  int rt = -1;
  int tables = 0;
  int rounds = 0;

  int arraySize = 0;
  int tableMax = ACBLSP_MOVEMENT_NTABLES_INDIVIDUAL_MAX;
  int roundMax = ACBLSP_MOVEMENT_NROUNDS_INDIVIDUAL_MAX;
  int lineMax  = 5;

  struct movement Move;
// ........................
//  Setup Movement Control

  Move.movement_controlp          = (struct acblsp_control *) NULL;
  Move.movement_structure_version = ACBLSP_STRUCTURE_VERSION_VALID;

  Move.movement_function = ACBLSP_MOVEMENT_FUNCTION_CALCULATE_MOVEMENT;
//  Move.movement_function = ACBLSP_MOVEMENT_FUNCTION_CHECK_STRUCTURE;
//  Move.movement_function = ACBLSP_MOVEMENT_FUNCTION_PRINT_STRUCTURE;
//  Move.movement_function = ACBLSP_MOVEMENT_FUNCTION_INIT_STRUCTURE;
//  Move.movement_function = ACBLSP_MOVEMENT_FUNCTION_TEST_STRUCTURE;

//  Setup Movement Structure

  fscanf(stdin,"%d", &Move.movement_ntables);
  fscanf(stdin,"%d", &Move.movement_nboards_in_play);
  fscanf(stdin,"%d", &Move.movement_nrounds);
  fscanf(stdin,"%d", &Move.movement_nboards_per_round);
  fscanf(stdin,"%d", &Move.movement_max_boards_played);
  fscanf(stdin,"%d", &Move.movement_skip_after_this_round);
  fscanf(stdin,"%d", &Move.movement_table_board_1_starts_at);
  fscanf(stdin,"%d", &Move.movement_ew_pair_playing_board_1);

// Fixed for Mitchell

  Move.movement_is_barometer          = 0;
  Move.movement_is_one_winner         = 0;

// Not Used

  Move.movement_nrounds_played        = 1;
  Move.movement_bye_stand             = 0;
  Move.movement_phantom_pair_number   = 0;

  Move.movement_game_type = ACBLSP_MOVEMENT_GAME_TYPE_PAIRS;
  strcpy(Move.movement_filename,"DummyFile");

  Move.movement_error = ACBLSP_MOVEMENT_ERROR_UNDEFINED;

//  XML Control

  strcpy(Move.movement_xml_filename, "movement.xml");
  Move.movement_xml_fd                 = (FILE *) NULL;
  Move.movement_xml_depth              = 0;

// ------------------------
// Local variables

  tables = Move.movement_ntables;
  rounds = Move.movement_nrounds;
  arraySize = ACBLSP_MOVEMENT_MAX_ARRAY_SIZE;

// ------------------------
// Call Movement Creation Library
// ------------------------

  movement_function(&Move);

// ------------------------
// Display Movement Data
// ------------------------

// Output Results

  fprintf(stdout, "\n");
  fprintf(stdout, "===== Test:  Mitchell Movement Generation =====\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Input:\n");
  fprintf(stdout, "\n");
  fprintf(stdout, " Game Type:     %d\n", Move.movement_game_type);
  fprintf(stdout, "\n");
  fprintf(stdout, " Tables:        %d\n", Move.movement_ntables);
  fprintf(stdout, " Rounds:        %d\n", Move.movement_nrounds);
  fprintf(stdout, " Boards:        %d\n", Move.movement_nboards_in_play);
  fprintf(stdout, " Board Per Set: %d\n", Move.movement_nboards_per_round);
  fprintf(stdout, " Start Table:   %d\n", 
    Move.movement_table_board_1_starts_at);
  fprintf(stdout, " Start E/W:     %d\n", 
    Move.movement_ew_pair_playing_board_1);
  fprintf(stdout, " Skip Round:    %d\n", Move.movement_skip_after_this_round);
  fprintf(stdout, "\n");
  fprintf(stdout, " Phantom Pair:  %d\n", Move.movement_phantom_pair_number);
  fprintf(stdout, " Byestand: (1)  %d\n", Move.movement_bye_stand);
  fprintf(stdout, " Barometer:     %d\n", Move.movement_is_barometer);
  fprintf(stdout, " One Winner:    %d\n", Move.movement_is_one_winner);
  fprintf(stdout, " XML File:      %s\n", Move.movement_filename);
  fprintf(stdout, " Relay Table:   *** Not Available ***\n");
  fprintf(stdout, " Rover Pair:    *** Not Available ***\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Output:\n");
  fprintf(stdout, "\n");
  fprintf(stdout, " Error Code:    %d\n", Move.movement_error);
  fprintf(stdout, " Array Size:    %d\n", arraySize);
  fprintf(stdout, "\n");

  for(r=0; r<rounds; r++)
  {
    fprintf(stdout, "*** Round: %d \n", r+1);
    for(t=0; t<tables; t++)
    {
        rt = t*(roundMax * lineMax) + r*lineMax;
        fprintf(stdout, " %d ", Move.movement_array[rt]);
        fprintf(stdout, " %d ", Move.movement_array[rt+1]);
        fprintf(stdout, " %d ", Move.movement_array[rt+2]);
        fprintf(stdout, "\n");
    }
  }

  fprintf(stdout, "=====\n");
  fprintf(stdout, "done\n");
  fprintf(stdout, "=====\n");
}

