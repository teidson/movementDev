#ifndef __ACBLSP_MOVEMENT_H__
#define __ACBLSP_MOVEMENT_H__ 1
// Copyright 2012 Hammond Software

// There are multiple defines used within this file to 
//
// structure_version - this is the version number of the structure.
// 	Only the number 493 is supported at the moment
// 	The idea is that as new versions of the structure are created it is
// 	possible that older programs can understand the type of the structure
// 	This is a weird number - 493 - deliberately chosen to make sure that the
// 	structure is valid
// 	If the program does not support the version number of the _structure_
// 	then an error is returned
//
// function - list of different functions supported by the code
//  see set of defines for list of supported functions
//
// Most of this information is taken from the PairSections code in ACBLscore+
//
// There may well be additional information that we need, this is considered a start
// Values passed in:
//	movement_ntables
//	movement_nboards_in_play
//	movement_nrounds
//	movement_nboards_per_round
//	movement_max_boards_played
//	movement_nrounds_played
//	movement_type
//	movement_filename
//	movement_table_board_1_starts_at
//	movement_ew_pair_playing_board_1
//	movement_skip_after_this_round
//	movement_bye_stand
//	movement_is_barometer
//	movement_phantom_pair_number
//	movement_is_one_winner
//	NEWFIELDS

// Values passed out:
//  2bd

#define ACBLSP_STRUCTURE_VERSION_MIN 497
#define ACBLSP_STRUCTURE_VERSION_VALID 497
#define ACBLSP_STRUCTURE_VERSION_MAX 497

#define ACBLSP_MOVEMENT_FUNCTION_MIN 1
#define ACBLSP_MOVEMENT_FUNCTION_INIT_STRUCTURE 1
#define ACBLSP_MOVEMENT_FUNCTION_CALCULATE_MOVEMENT 2
#define ACBLSP_MOVEMENT_FUNCTION_PRINT_STRUCTURE 3
#define ACBLSP_MOVEMENT_FUNCTION_CHECK_STRUCTURE 4
#define ACBLSP_MOVEMENT_FUNCTION_TEST_STRUCTURE 5
#define ACBLSP_MOVEMENT_FUNCTION_MAX 5

// Max is tables * rounds * (ndirections + 1)
// The +1 is the start_board for the round
// Max for pairs event is 40x25x3=3000
// Max for ind event is 20x36x5=3600
// TODO Set correct MAX values
#define ACBLSP_MOVEMENT_MAX_ARRAY_SIZE 3600

#define ACBLSP_MOVEMENT_NTABLES_MIN 1 
#define ACBLSP_MOVEMENT_NTABLES_PAIRS_MAX 40
#define ACBLSP_MOVEMENT_NTABLES_INDIVIDUAL_MAX 20
#define ACBLSP_MOVEMENT_NBOARDS_IN_PLAY_MIN 1
#define ACBLSP_MOVEMENT_NBOARDS_IN_PLAY_MAX 999
#define ACBLSP_MOVEMENT_NROUNDS_MIN 1
#define ACBLSP_MOVEMENT_NROUNDS_PAIRS_MAX 25
#define ACBLSP_MOVEMENT_NROUNDS_INDIVIDUAL_MAX 36
#define ACBLSP_MOVEMENT_NBOARDS_PER_ROUND_MIN 1
#define ACBLSP_MOVEMENT_NBOARDS_PER_ROUND_MAX 999
#define ACBLSP_MOVEMENT_MAX_BOARDS_PLAYED_MIN 1
#define ACBLSP_MOVEMENT_MAX_BOARDS_PLAYED_MAX 999
#define ACBLSP_MOVEMENT_NROUNDS_PLAYED_MIN 1
#define ACBLSP_MOVEMENT_NROUNDS_PLAYED_MAX 999

#define ACBLSP_MOVEMENT_GAME_TYPE_MIN 1
#define ACBLSP_MOVEMENT_GAME_TYPE_PAIRS 1
#define ACBLSP_MOVEMENT_GAME_TYPE_IND 2
// How is BAM different? TODO
#define ACBLSP_MOVEMENT_GAME_TYPE_BAM 3
#define ACBLSP_MOVEMENT_GAME_TYPE_MAX 2

#define ACBLSP_MOVEMENT_FILENAME_MIN 1
#define ACBLSP_MOVEMENT_FILENAME_MAX 999

#define ACBLSP_MOVEMENT_TABLE_BOARD_1_STARTS_AT_MIN 1
#define ACBLSP_MOVEMENT_TABLE_BOARD_1_STARTS_AT_MAX 40
#define ACBLSP_MOVEMENT_EW_PAIR_PLAYING_BOARD_1_MIN 1
#define ACBLSP_MOVEMENT_EW_PAIR_PLAYING_BOARD_1_MAX 40
#define ACBLSP_MOVEMENT_SKIP_AFTER_THIS_ROUND_MIN 0
#define ACBLSP_MOVEMENT_SKIP_AFTER_THIS_ROUND_MAX 40
#define ACBLSP_MOVEMENT_BYE_STAND_MIN 0
#define ACBLSP_MOVEMENT_BYE_STAND_MAX 40
#define ACBLSP_MOVEMENT_IS_BAROMETER_MIN 0
#define ACBLSP_MOVEMENT_IS_BAROMETER_MAX 1
#define ACBLSP_MOVEMENT_IS_ONE_WINNER_MIN 0
#define ACBLSP_MOVEMENT_IS_ONE_WINNER_MAX 1
#define ACBLSP_MOVEMENT_PHANTOM_PAIR_NUMBER_MIN -40
#define ACBLSP_MOVEMENT_PHANTOM_PAIR_NUMBER_MAX 40
// NEWFIELDS - Add min/max information on new fields above here

struct movement {
	struct acblsp_control *movement_controlp;
				// These are all values that are expected to be passed in
	int movement_structure_version;	// Expected to be 1.
	int movement_function; // What to do with the structure

	// Following are all expected to be passed in
	int movement_ntables;
	int movement_nboards_in_play;
	int movement_nrounds;
	int movement_nboards_per_round;
	int movement_max_boards_played;
	int movement_nrounds_played;
	int movement_game_type;
	char movement_filename[80];
	int movement_table_board_1_starts_at;
	int movement_ew_pair_playing_board_1;
	int movement_skip_after_this_round;
	int movement_bye_stand;
	int movement_is_barometer;
	int movement_phantom_pair_number;
	int movement_is_one_winner;

// NEWFIELDS - Add new input fields above this, output fields below this
//
	// Following are expected to be passed out
	//int movement_array[40][30][5];
	int movement_array[ACBLSP_MOVEMENT_MAX_ARRAY_SIZE];

	// Set if there is an error
	int movement_error;

	// For printing out XML data.
	char movement_xml_filename[80];	// Note there is no malloc
	FILE *movement_xml_fd;
	int movement_xml_depth;
};

#endif /* __ACBLSP_MOVEMENT_H__ */

