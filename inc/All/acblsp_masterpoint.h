#ifndef __ACBLSP_MASTERPOINT_H__
#define __ACBLSP_MASTERPOINT_H__ 1
// Copyright 2012 Hammond Software

// There are multiple defines used within this file to 
//
// structure_version - this is the version number of the structure.
// 	Only the number 493 is supported at the moment
// 	The idea is that as new versions of the structure are created it is
// 	possible that older programs can understand the type of the structure
// 	This is a wierd number - 493 - deliberately chosen to make sure that the
// 	structure is valid
// 	If the program does not support the version number of the _structure_
// 	then an error is returned
//
// function - list of different functions supported by the code
//  see set of defines for list of supported functions
//
// event_start_date_time - time format in time_t
// 	The event start date affects the masterpoint calculation that can be used
// 	This particularly applies when an update is made to the masterpoint formula
//
// mp_revision_to_use -
//  If 0, this is the default, currently defined as option 1.
// 	If 1, it will use the formula in place as of the event_start_date_time
// 	Note that this code only supports the MP formula in place since Jan 2012.
// 	If 2, it will use the current formula in place as of the moment
// 	If 3, it will use a custom formula (non supported)
// 	If <n>, then it will use that version number. Note that no 'n' is
// 	 supported at the moment.
// 	 This option is supported to allow for proposed changes to be tested
// 	Other revisions may be supported at the moment
//
// rounding_formula_to_use
// 	If 0, will use the default formula
// 	The default formula will be the formula currently in place
// 	Setting it to 0, is the same as setting it to 1 (currently)
//
// 	If 1, this will use the same rounding algorithm that ACBLscore uses.
// 	This implements the current ACBLscore algorithm.
// 	It may seem silly to have to specify a rounding algorithm, but ACBLscore is 
// 	written in Pascal and uses its own rounding algorithm which then calls
// 	the Pascal library rounding function. The Pascal library uses a 
// 	banker's round which is not common. 
// 	Also there is rounding, then multiplication, then rounding again. 
// 	All ACBL games must use this option.
//
// 	The value 2 is not supported yet.
//
// d_ntables - number of tables
// 	Note that half tables are supported
//
//
#define ACBLSP_MP_STRUCTURE_VERSION_MIN 493
#define ACBLSP_MP_STRUCTURE_VERSION_VALID 493
#define ACBLSP_MP_STRUCTURE_VERSION_MAX 493

#define ACBLSP_MP_FUNCTION_MIN 1
#define ACBLSP_MP_FUNCTION_INIT_MP_STRUCTURE 1
#define ACBLSP_MP_FUNCTION_CALCULATE_MASTERPOINTS 2
#define ACBLSP_MP_FUNCTION_PRINT_MP_STRUCTURE 3
#define ACBLSP_MP_FUNCTION_CHECK_MP_STRUCTURE 4
#define ACBLSP_MP_FUNCTION_NEXT_VAL 5
#define ACBLSP_MP_FUNCTION_PRINT_APPENDIX_A 6
#define ACBLSP_MP_FUNCTION_PRINT_APPENDIX_B 7
#define ACBLSP_MP_FUNCTION_PRINT_APPENDIX_C 8
#define ACBLSP_MP_FUNCTION_PRINT_APPENDIX_D 9
#define ACBLSP_MP_FUNCTION_PRINT_APPENDIX_E 10
#define ACBLSP_MP_FUNCTION_TEST_MP_STRUCTURE 11
#define ACBLSP_MP_FUNCTION_MAX 11

#define ACBLSP_MP_REVISION_MIN 0
#define ACBLSP_MP_REVISION_EVENT_START_DATE 0
#define ACBLSP_MP_REVISION_CURRENT_FORMULA 1
#define ACBLSP_MP_REVISION_CUSTOM_FORMULA 2
#define ACBLSP_MP_REVISION_MAX 2

#define ACBLSP_MP_ROUNDING_FORMULA_MIN 0
#define ACBLSP_MP_ROUNDING_FORMULA_DEFAULT 0
#define ACBLSP_MP_ROUNDING_FORMULA_ACBLSCORE 1
#define ACBLSP_MP_ROUNDING_FORMULA_ACBLSCORE_PLUS 2
#define ACBLSP_MP_ROUNDING_FORMULA_MAX 2

// No maximum for number of tables
#define ACBLSP_MP_NTABLES_MIN 0

// Classification not used any more
#define ACBLSP_MP_CLASSIFICATION_MIN 0
#define ACBLSP_MP_CLASSIFICATION_NOT_SET 0
#define ACBLSP_MP_CLASSIFICATION_UNIT_CHAMPIONSHIP 1
#define ACBLSP_MP_CLASSIFICATION_SECTIONAL 2
#define ACBLSP_MP_CLASSIFICATION_REGIONAL 3
#define ACBLSP_MP_CLASSIFICATION_NATIONAL 4
#define ACBLSP_MP_CLASSIFICATION_MAX 4

// The C structures will be off by 1
#define ACBLSP_MP_EVENT_RATING_MIN 1
#define ACBLSP_MP_EVENT_RATING_CLUB_RATING_POINT 1
#define ACBLSP_MP_EVENT_RATING_CLUB_CHAMPIONSHIP 2
#define ACBLSP_MP_EVENT_RATING_CHARITY_CHAMPIONSHIP 3
#define ACBLSP_MP_EVENT_RATING_UNIT_CHAMPIONSHIP 4
#define ACBLSP_MP_EVENT_RATING_SECTIONAL 5
#define ACBLSP_MP_EVENT_RATING_REGIONAL 6
#define ACBLSP_MP_EVENT_RATING_INTERNATIONAL_FUND 7
#define ACBLSP_MP_EVENT_RATING_ACBL_MEMBERSHIP 8
#define ACBLSP_MP_EVENT_RATING_GNT_NAP 9
#define ACBLSP_MP_EVENT_RATING_CNTC_COPC 10
#define ACBLSP_MP_EVENT_RATING_ACBL_WIDE 11
#define ACBLSP_MP_EVENT_RATING_UPGRADED_CLUB_CHAMPIONSHIP 12
#define ACBLSP_MP_EVENT_RATING_NATIONAL 13
#define ACBLSP_MP_EVENT_RATING_STAC 14
#define ACBLSP_MP_EVENT_RATING_MAX 63

#define ACBLSP_MP_CHAMPIONSHIP_RATING_MIN 1
#define ACBLSP_MP_CHAMPIONSHIP_RATING_CLUB_RATING_POINT 1
#define ACBLSP_MP_CHAMPIONSHIP_RATING_CLUB_CHAMPIONSHIP 2
#define ACBLSP_MP_CHAMPIONSHIP_RATING_CHARITY_CHAMPIONSHIP 3
#define ACBLSP_MP_CHAMPIONSHIP_RATING_UNIT_CHAMPIONSHIP 4
#define ACBLSP_MP_CHAMPIONSHIP_RATING_SECTIONAL 5
#define ACBLSP_MP_CHAMPIONSHIP_RATING_REGIONAL 6
#define ACBLSP_MP_CHAMPIONSHIP_RATING_INTERNATIONAL_FUND 7
#define ACBLSP_MP_CHAMPIONSHIP_RATING_ACBL_MEMBERSHIP 8
#define ACBLSP_MP_CHAMPIONSHIP_RATING_GNT_NAP 9
#define ACBLSP_MP_CHAMPIONSHIP_RATING_CNTC_COPC 10
#define ACBLSP_MP_CHAMPIONSHIP_RATING_ACBL_WIDE 11
#define ACBLSP_MP_CHAMPIONSHIP_RATING_UPGRADED_CLUB_CHAMPIONSHIP 12
#define ACBLSP_MP_CHAMPIONSHIP_RATING_NATIONAL 13
#define ACBLSP_MP_CHAMPIONSHIP_RATING_STAC 14
#define ACBLSP_MP_CHAMPIONSHIP_RATING_MAX 63

#define ACBLSP_MP_NSESSIONS_MIN 1
#define ACBLSP_MP_NSESSIONS_MAX 6

#define ACBLSP_MP_NSTRATS_MIN 1
#define ACBLSP_MP_NSTRATS_MAX 6

// No upper limit max
#define ACBLSP_MP_UPPER_LIMIT_MIN 0
//#define ACBLSP_MP_UPPER_LIMIT_MAX 6

#define ACBLSP_MP_NRESTRICTIONS_MIN 0

#define ACBLSP_MP_TYPE_OF_EVENT_MIN 1
#define ACBLSP_MP_TYPE_OF_EVENT_INDIVIDUAL 1
#define ACBLSP_MP_TYPE_OF_EVENT_PAIR 2
#define ACBLSP_MP_TYPE_OF_EVENT_SWISS 3
#define ACBLSP_MP_TYPE_OF_EVENT_KO 4
#define ACBLSP_MP_TYPE_OF_EVENT_BAM 5
#define ACBLSP_MP_TYPE_OF_EVENT_MAX 5

#define ACBLSP_MP_EVENT_TYPE_MIN 1
#define ACBLSP_MP_EVENT_TYPE_INDIVIDUAL 1
#define ACBLSP_MP_EVENT_TYPE_PAIR 2
#define ACBLSP_MP_EVENT_TYPE_SWISS 3
#define ACBLSP_MP_EVENT_TYPE_KO 4
#define ACBLSP_MP_EVENT_TYPE_BAM 5
#define ACBLSP_MP_EVENT_TYPE_MAX 5

#define ACBLSP_MP_GAME_TYPE_MIN 1
#define ACBLSP_MP_GAME_TYPE_INDIVIDUAL 1
#define ACBLSP_MP_GAME_TYPE_PAIR 2
#define ACBLSP_MP_GAME_TYPE_SWISS 3
#define ACBLSP_MP_GAME_TYPE_KO 4
#define ACBLSP_MP_GAME_TYPE_BAM 5
#define ACBLSP_MP_GAME_TYPE_MAX 5

#define ACBLSP_MP_IS_NABC_EVENT_BITMASK 0x1
#define ACBLSP_MP_IS_CLUB_GAME_BITMASK 2
#define ACBLSP_MP_IS_SEPARATE_FLIGHT_A_EVENT_BITMASK 0x4
#define ACBLSP_MP_HAS_MULTIPLE_SECTIONS_BITMASK 0x8
#define ACBLSP_MP_IS_THREE_SESSION_KO_BITMASK 0x10
#define ACBLSP_MP_IS_SPLIT_REGIONAL_BITMASK 0x20
#define ACBLSP_MP_IS_STRATIFIED_BITMASK 0x40
#define ACBLSP_MP_IS_STRATIFLIGHTED_BITMASK 0x80
#define ACBLSP_MP_IS_COMPACT_KO_BITMASK 0x100
#define ACBLSP_MP_IS_COMPACT_KO_CONSOLATION_BITMASK 0x200
#define ACBLSP_MP_IS_SPECIAL_BENEFICIARY_EVENT_BITMASK 0x400
#define ACBLSP_MP_IS_CONSOLATION_EVENT_BITMASK 0x800
	// Don't like negative. Consider changing
#define ACBLSP_MP_IS_NON_CHAMPIONSHIP_BITMASK 0x1000

#define ACBLSP_MP_IS_NABC_EVENT(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_NABC_EVENT_BITMASK)
#define ACBLSP_MP_IS_CLUB_GAME(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_CLUB_GAME_BITMASK)
#define ACBLSP_MP_IS_SEPARATE_FLIGHT_A_EVENT(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_SEPARATE_FLIGHT_A_EVENT_BITMASK)
#define ACBLSP_MP_HAS_MULTIPLE_SECTIONS(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_HAS_MULTIPLE_SECTIONS_BITMASK)
#define ACBLSP_MP_IS_THREE_SESSION_KO(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_THREE_SESSION_KO_BITMASK)
#define ACBLSP_MP_IS_SPLIT_REGIONAL(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_SPLIT_REGIONAL_BITMASK)
#define ACBLSP_MP_IS_STRATIFIED(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_STRATIFIED_BITMASK)
#define ACBLSP_MP_IS_STRATIFLIGHTED(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_STRATIFLIGHTED_BITMASK)
#define ACBLSP_MP_IS_COMPACT_KO(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_COMPACT_KO_BITMASK)
#define ACBLSP_MP_IS_COMPACT_KO_CONSOLATION(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_COMPACT_KO_CONSOLATION_BITMASK)
#define ACBLSP_MP_IS_SPECIAL_BENEFICIARY_EVENT(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_SPECIAL_BENEFICIARY_EVENT_BITMASK)
#define ACBLSP_MP_IS_CONSOLATION_EVENT(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_CONSOLATION_EVENT_BITMASK)
#define ACBLSP_MP_IS_NON_CHAMPIONSHIP(MPP) \
				(MPP->mstpt_flags_1 && ACBLSP_MP_IS_NON_CHAMPIONSHIP_BITMASK)

// Set a maximum number of strats
#define ACBLSP_MP_MAX_STRATS 8

struct masterpoint {
	struct acblsp_control *mstpt_controlp;
				// These are all values that are expected to be passed in
	int mstpt_structure_version;	// Expected to be 1.
	int mstpt_function; // What to do with the structure
	time_t	mstpt_event_start_date_time; // Event start time. Used to determine MP formula to use
	int mstpt_mp_revision_to_use; // If 0, use the one that applies to event date
//	int rounding_formula; // If 1, old ACBLscore, 2=new ACBLscore+
	int mstpt_rounding_formula; // If 1, old ACBLscore, 2=new ACBLscore+
	int mstpt_event_rating; // Event rating
	int mstpt_championship_rating; // Championship rating
	int mstpt_nsessions;	// Number of sessions
	int mstpt_nstrats;	// Number of flights
	int mstpt_nrestrictions;		// Number of restrictions - calculates p_factor
	int mstpt_game_type;		// Event type (BAM, Pairs, Swiss, Individual) - t_factor
//	int mstpt_type_of_event;		// Event type (BAM, Pairs, Swiss, Individual) - t_factor
	int mstpt_event_type;		// Event type (BAM, Pairs, Swiss, Individual) - t_factor
		// ntables can have 0.5 in them
	double mstpt_d_ntables[ACBLSP_MP_MAX_STRATS];
	int mstpt_upper_limit[ACBLSP_MP_MAX_STRATS];		// Masterpoint upper limit for event - m_factor
//	int event_game_type;		// Event type (BAM, Pairs, Swiss, Individual) - t_factor
//	int score_method;		// Score method
  int mstpt_flags_1;
  int mstpt_flags_2;	// Not used, for expansion
	int mstpt_nabc_event_number;	// Only used if this is an NABC event
	int mstpt_ncuts_so_far;		// Number of cuts so far for qualifying game
	int mstpt_nrounds;
	int mstpt_nteams_in_bracket;
	int mstpt_nboards_per_match;
	int mstpt_average_mp_in_bracket;
	int mstpt_mp_for_higher_bracket_100;
	double mstpt_d_mp_for_higher_bracket;

	int mstpt_nbo;	// 1=ACBL, 2=ABA, 3=WBF, other are 2bf

	// Here's a hint, if adding something, use spare_5 first!
  int mstpt_spare1;	// Not used, for future expansion
  int mstpt_spare2;	// Not used, for future expansion
  int mstpt_spare3;	// Not used, for future expansion
  int mstpt_spare4;	// Not used, for future expansion
  int mstpt_spare5;	// Not used, for future expansion

  double mstpt_d_spare1;	// Not used, for future expansion
  double mstpt_d_spare2;	// Not used, for future expansion
  double mstpt_d_spare3;	// Not used, for future expansion
  double mstpt_d_spare4;	// Not used, for future expansion
  double mstpt_d_spare5;	// Not used, for future expansion

	// double first_place_award;
	int mstpt_depth_of_overall_awards[ACBLSP_MP_MAX_STRATS];
	int mstpt_depth_of_session_awards[ACBLSP_MP_MAX_STRATS];
	double mstpt_d_overall_awards[ACBLSP_MP_MAX_STRATS][50];
	int mstpt_overall_awards_100[ACBLSP_MP_MAX_STRATS][50];
	int mstpt_overall_awards_mp_colors[ACBLSP_MP_MAX_STRATS][50];
	double mstpt_d_session_awards[ACBLSP_MP_MAX_STRATS][50];
	int mstpt_session_awards_100[ACBLSP_MP_MAX_STRATS][50];
	int mstpt_session_awards_mp_colors[ACBLSP_MP_MAX_STRATS][50];
	double mstpt_d_match_award;
	int mstpt_match_award_100;

	// These are values that will be calculated and returned
	double mstpt_d_b_factor[ACBLSP_MP_MAX_STRATS];
	double mstpt_d_d_factor;
	double mstpt_d_k_factor;	// Based on rating
	double mstpt_d_l_factor;	// Number of boards per match
	double mstpt_d_m_factor[ACBLSP_MP_MAX_STRATS];	// Based on masterpoint upper limit for event
	double mstpt_d_p_factor;	// Restrictions - more restrictions, lower
	double mstpt_d_r_factor;
	double mstpt_d_s_factor;
	double mstpt_d_t_factor;	// Type factor e.g. (BAM/Pairs/Swiss/Individual)
	double mstpt_d_basic_award;

	double mstpt_d_ko_reduction_factor; // Reduction factor for KO

	int mstpt_ntables_for_mp_calculations;
	int mstpt_mp_version;	// Masterpoint formula used
	int mstpt_program_version;	// Version of program used to calculate

	// Set if there is an error
	int mstpt_error;

  int mstpt_msg_flags_1;	// Different bits set if a message should be relayed
  int mstpt_msg_flags_2;	// Not used, for expansion
  int mstpt_msg_flags_3;	// Not used, for expansion
  int mstpt_msg_flags_4;	// Not used, for expansion

	int mstpt_c_strat;	// Internal use for current strat to process
								// Value never used externally
	
	// For printing out XML data.
	char mstpt_xml_filename[80];	// Note there is no malloc
	FILE *mstpt_xml_fd;
	int mstpt_xml_depth;
};

#endif /* __ACBLSP_MASTERPOINT_H__ */

