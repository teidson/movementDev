#ifndef __ACBL_CONSTANTS_H__
#define __ACBL_CONSTANTS_H__ 1
/* 
 * Copyright 2012 Hammond Software
 * Constants for new version of ACBLscore
 * Use acblsp_constants for all new constants
 * Some of the old constants are in the new file
 *
 * If you make any changes to this file, i.e. constants, make sure that the
 * same changes are made to the Ruby ./config/initializers/acbl_constants.rb
 */

#define     ACBL_VerNeeded		747
#define     ACBL_MaxEvents		50
#define     ACBL_MaxSections		100
#define     ACBL_MaxStrat    	3
#define     ACBL_MaxBoards   	80
#define     ACBL_MaxMatches  	20
#define     ACBL_MaxOldMatches 	99
#define     ACBL_MaxTables   	40
#define     ACBL_MaxDirection 	4
#define     ACBL_MaxTeamSize 	6
#define     ACBL_MaxMemos    	2
#define     ACBL_MaxMemoLen  	63
#define     ACBL_MaxNotes    	20
#define     ACBL_MaxNoteLen  	75
#define     ACBL_MaxOARank   	2010
#define     ACBL_MaxTeams    	700
#define     ACBL_MaxTeamNo   	800
#define     ACBL_ByeTeamNo   	888
#define     ACBL_FoulGroups		8

/* #define     DefRRTol    	50{65} */

#define     ACBL_MaxRoundRobin 	2

/* Don't know how to port orig. Pascal dec ACBL_MaxTeamComb 19{20{6} to C */

#define     ACBL_MaxTeamComb   	19

#define     ACBL_MaxTeamSess 	50

#define     ACBL_MaxVP       	68
#define     ACBL_MaxStat     	4
#define     ACBL_ManualQOff  	10000
#define     ACBL_NeligQOff   	5000

#define     ACBL_PrevMPs        	1  /* previous session mps */
#define     ACBL_SessMPs        	2  /* this session mps */
#define     ACBL_TotMPs         	3  /* event mps */


#define     ACBL_MaxRecTypes 	16

/* From mpdef.pas */
#define ACBL_MaxMPTypes	3

     /* Ribbon constants */
#define	ACBL_rbNone         0
#define	ACBL_rbBlue         1
#define	ACBL_rbRed          2
#define	ACBL_rbSilver       3
#define	ACBL_rbBlueRed      9

     /* {club mp factors} */
#define ACBL_CLUB_MP_FACTOR_Open      100
#define ACBL_CLUB_MP_FACTOR_Inv       80
#define ACBL_CLUB_MP_FACTOR_200       70
#define ACBL_CLUB_MP_FACTOR_100       60
#define ACBL_CLUB_MP_FACTOR_20        50
#define ACBL_CLUB_MP_FACTOR_10        40
#define ACBL_CLUB_MP_FACTOR_BP        30
#define ACBL_CLUB_MP_FACTOR_Pupil     20
#define ACBL_CLUB_MP_FACTOR_Intro     10
#define ACBL_CLUB_MP_FACTOR_SeriesFact  2

	/* Pascal enum type - careful */
	/* type TClubGameType = ( */
#define ACBL_CLUB_GAME_TYPE_Open			1
#define ACBL_CLUB_GAME_TYPE_Inv				2
#define ACBL_CLUB_GAME_TYPE_Nov				3
#define ACBL_CLUB_GAME_TYPE_BP				4
#define ACBL_CLUB_GAME_TYPE_Pupil			5
#define ACBL_CLUB_GAME_TYPE_Intro			6

	/* const {maximum number of foul groups} */
#define     ACBL_FoulGroups  8

	/*      {score offset for each foul group}
     FoulOffSet   : Array[1..FoulGroups] of SmallInt =
                   (0,4000,6000,8000,10000,12000,14000,16000);
	*/

/* const MacToRun     : String[30] = ''; */

	/* const {characters for tagging foul groups}
     FoulChar     : String[FoulGroups] = ' FGHIJKL';
	*/

	/* const {score constants}
     scLate       = 900;        {late play}
     scNotPlayed  = 950;        {not played}
     scInActive   = 999;        {no score}
     scAminus     = 2040;       {ave-}
     scAve        = 2050;       {ave}
     scAplus      = 2060;       {ave+}
     scArb        = 20000;      {arbitrary matchpoint score}
     scArbOffSet  = 200000;     {offset for arbitrary matchpoint}
     scPOffSet    = 22000;      {offset for protected score (ave+ or better}
     scQOffset    = 24000;      {offset for reverse protected score
                                 (ave- or worse}
     d_ps       = 2;            {precision, decimal places}
     s_prec     = 100;          {score factor for 2 decimal places}
const
     DispWidth  : byte = 8;     {width of displayed scores}
     s_half     : word = s_prec div 2; {value of 1/2 matchpoint}
     s_one      : word = s_prec;    {value of 1 matchpoint}
     s_two      : word = s_prec * 2;{value of 1 matchpoint (European)}
	*/
#define ACBL_scLate       900
#define ACBL_scNotPlayed  950
#define ACBL_scInActive   999
#define ACBL_scAminus     2040
#define ACBL_scAve        2050
#define ACBL_scAplus      2060
#define ACBL_scArb        20000
#define ACBL_scArbOffset  200000
#define ACBL_scPOffset    22000
#define ACBL_scQOffset    24000

#define ACBL_d_ps       2
#define ACBL_s_prec     100
#ifdef LATER
#define DispWidth  : byte = 8;     {width of displayed scores}
#define s_half     : word = s_prec div 2; {value of 1/2 matchpoint}
#define s_one      : word = s_prec;    {value of 1 matchpoint}
#define s_two      : word = s_prec * 2;{value of 1 matchpoint (European)}
#endif

#ifdef ORIG_PASCAL
// From SwissTeamOptions
#define moQuickMatch 	 0x0001; {pair teams while posting}
#define moPrResults  	 0x0002; {print results as posted}
#define moPrPairings 	 0x0004; {print pairings as they happen}
#define moRangeOnly  	 0x0008; {pair only out of range teams}
#define moNoAnnounce 	 0x0010; {do not announce new pairings on screen}
#define moShowResults	 0x0020; {announce results to screen}
#define moShortRR    	 0x0040; {use short RR (one match)}
#define moAskRRagain 	 0x0080; {ask confirmation for second rr attendance}
#define moRoundRobin 	 0x0100; {round robin event}
#define moAWLRR2     	 0x0200; {American Whist League RR movement comp after 2}
#define moAWLRRall   	 0x0400; {American Whist League RR movement comp at end}
#define moAskBackup  	 0x0800; {Ask for backup after round posted}
#define moIsKO       	 0x1000; {Knockout event}
#define moPairStat   	 0x2000; {Pair stationary teams without asking}
#define moCisCons    	 0x4000; {Compact KO with no consolation - teams continue}
     pefManualMP    = $01; {mps adjusted manually for this player}
     pefDiffRank    = $02; {KO player rank is <> team rank}
     pefNameEntered = $04; {Name manually entered (not XOVed)}
     pefNoKOrank    = $08; {no KO rank (used for 3-way playoff matches)}

    elnoOA       = $02;         {not elegible for overall}
    elDoubleSess = $04;         {double session rank}
    elnoSess     = $08;         {no session rank}
    elDoubleOA   = $10;         {double overall rank}
#endif
#define ACBL_moQuickMatch 	 0x0001
#define ACBL_moPrResults  	 0x0002
#define ACBL_moPrPairings 	 0x0004
#define ACBL_moRangeOnly  	 0x0008
#define ACBL_moNoAnnounce 	 0x0010
#define ACBL_moShowResults	 0x0020
#define ACBL_moShortRR    	 0x0040
#define ACBL_moAskRRagain 	 0x0080
#define ACBL_moRoundRobin 	 0x0100
#define ACBL_moAWLRR2     	 0x0200
#define ACBL_moAWLRRall   	 0x0400
#define ACBL_moAskBackup  	 0x0800
#define ACBL_moIsKO       	 0x1000
#define ACBL_moPairStat   	 0x2000
#define ACBL_moCisCons    	 0x4000

#define ACBL_pefManualMP    0x01
#define ACBL_pefDiffRank    0x02
#define ACBL_pefNameEntered 0x04
#define ACBL_pefNoKOrank    0x08

#define ACBL_elnoOA       	 0x02
#define ACBL_elDoubleSess 	 0x04
#define ACBL_elnoSess     	 0x08
#define ACBL_elDoubleOA   	 0x10


/* {scoring methods} TScoreMethod = (smMatch,    { 0=matchpoints}
                    smDIMP,     { 1=datum IMPs}
                    smAIMP,     { 2=average IMPs}
                    smTIMP,     { 3=total IMPs}
                    smInst,     { 4=instant matchpoints}
                    smBAM,      { 5=board-a-match matchpoints}
                    smWinLoss,  { 6=win-loss}
                    smVP,       { 7=victory points}
                    smKO,       { 8=knockout}
                    smZKO,      { 9=zip knockout (one session)}
                    smOAonly,   {10=continuous pairs final}
                    smName,     {11=name entry only}
                    smBIMP,     {12=board-a-match IMPs}
                    smPDIMP,    {13=predetermined datum IMPs}
                    smMatchE,   {14=matchpoints - no halves - European}
                    smTotal,    {15=total points}
                    smSBAM,     {16=Swiss BAM matchpoints}
                    smBracket,  {17=Bracketing assignments}
                    smCKO,      {18=Compact KO}
                    smPDBAM);   {19=Predetermined BAM pairs}
*/

#define ACBL_smMatch		0	/* 0=matchpoints */
#define ACBL_smDIMP		1	/* 1=datum IMPs */
#define ACBL_smAIMP		2	/* 2=average IMPs */
#define ACBL_smTIMP		3	/* 3=total IMPs */
#define ACBL_smInst		4	/* 4=instant matchpoints */
#define ACBL_smBAM		5	/* 5=board-a-match matchpoints */
#define ACBL_smWinLoss	6	/* 6=win-loss */
#define ACBL_smVP		7	/* 7=victory points */
#define ACBL_smKO		8	/* 8=knockout */
#define ACBL_smZKO		9	/* 9=zip knockout (one session) */
#define ACBL_smOAonly	10	/* 10=continuous pairs final */
#define ACBL_smName		11	/* 11=name entry only */
#define ACBL_smBIMP		12	/* 12=board-a-match IMPs */
#define ACBL_smPDIMP		13	/* 13=predetermined datum IMPs */
#define ACBL_smMatchE	14	/* 14=matchpoints - no halves - European */
#define ACBL_smTotal		15	/* 15=total points */
#define ACBL_smSBAM		16	/* 16=Swiss BAM matchpoints */
#define ACBL_smBracket	17	/* 17=Bracketing assignments */
#define ACBL_smCKO		18	/* 18=Compact KO */
#define ACBL_smPDBAM		19	/* 19=Predetermined BAM pairs */

// This starts a section of text defines
#ifdef MAIN
char *ACBL_TEXT_tscore_method[] = {
	"0=Matchpoints",
	"1=Datum IMPs",
	"2=Average IMPs",
	"3=Total IMPs",
	"4=Instant matchpoints",
	"5=Board-a-match matchpoints",
	"6=Win-loss",
	"7=Victory points",
	"8=Knockout",
	"9=Zip knockout (one session)",
	"10=Continuous pairs final",
	"11=Name entry only",
	"12=Board-a-match IMPs",
	"13=Predetermined datum IMPs",
	"14=Matchpoints - no halves - European",
	"15=Total points",
	"16=Swiss BAM matchpoints",
	"17=Bracketing assignments",
	"18=Compact KO",
	"19=Predetermined BAM pairs"
	};
char *ACBL_TEXT_sscore_method[] = {
	"Matchpoints",
	"Datum IMPs",
	"Average IMPs",
	"Total IMPs",
	"Instant matchpoints",
	"Board-a-match matchpoints",
	"Win-loss",
	"Victory points",
	"Knockout",
	"Zip knockout (one session)",
	"Continuous pairs final",
	"Name entry only",
	"Board-a-match IMPs",
	"Predetermined datum IMPs",
	"Matchpoints - no halves - European",
	"Total points",
	"Swiss BAM matchpoints",
	"Bracketing assignments",
	"Compact KO",
	"Predetermined BAM pairs"
	};
#else
extern char *ACBL_TEXT_tscore_method[];
extern char *ACBL_TEXT_sscore_method[];
#endif


// Same options as the old
// ACBLscore defines these 6 game types with these options
#define ACBL_GAME_TYPE_Pair		0
#define ACBL_GAME_TYPE_Team		1
#define ACBL_GAME_TYPE_Ind		2
#define ACBL_GAME_TYPE_HS			3
#define ACBL_GAME_TYPE_BAM		4
#define ACBL_GAME_TYPE_T2P    5  	/* 5=teams of two pairs */

// ACBLscore defines these 6 game types with these options
#define ACBL_GAME_TYPE_PAIR		0
#define ACBL_GAME_TYPE_TEAM		1
#define ACBL_GAME_TYPE_INDIVIDUAL			2
#define ACBL_GAME_TYPE_HOME_STYLE			3
#define ACBL_GAME_TYPE_BAM			4
#define ACBL_GAME_TYPE_TWO_PAIRS    5  	/* 5=teams of two pairs */

#define     ACBL_mNind      1
#define     ACBL_mEind      2
#define     ACBL_mBind      3

#define     ACBL_mSind      3
#define     ACBL_mWind      4
#define     ACBL_mIBind     5


// From scorevar.pas
// Global options values
#define ACBL_GlobalOptionsUseSameLetterInAllTeamEvents 0x1
#define ACBL_GlobalOptionsPrintTeamResultsInColumns 0x2
#define ACBL_GlobalOptionsGameFileHasBeenBackedUp 0x4
#define ACBL_GlobalOptionsError 0x8
/*
type
const
   Instant      : PInstant = nil;
   PDIMP        : PPDIMP = nil;
   Datums       : Array [1..FoulGroups] of PDatums  =
                (nil,nil,nil,nil,nil,nil,nil,nil);
   Note         : PNote = nil;
   {$ifdef TeamSessions}
   TeamSess     : PTeamSess = nil;
   {$endif}
     GameSig : String[3] = 'AC3';

     {Game file read only status}
     GFReadOnly  : boolean = false;
const
     {section colors}
     colors      : Array[0..6] of String[6] =
                 ('GRAY','WHITE','YELLOW','GREEN','ORANGE','BLUE','PINK');
*/

#ifdef MAIN
char *ACBL_TEXT_section_colors[] = {
		"GRAY",
		"WHITE",
		"YELLOW",
		"GREEN",
		"ORANGE",
		"BLUE",
		"PINK"};
#else
extern char *section_colors[];
#endif

/*
const
{ Vulnerability table: }
    vultbl       : Array[1..ACBL_MaxBoards] of byte =
                 (0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2,
                  0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2,
                  0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2,
                  0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2,
                  0,1,2,3,1,2,3,0,2,3,0,1,3,0,1,2);
const
    hitabsize     = 16;
    {hilight table for posting from pick-ups}
    hitab        : Array[0..3,1..hitabsize] of word =
       ((60,63,64,65,66,67,68,69,71,72,73,75,79,85,143,144),     {nv,nv}
        (40,45,55,92,94,98,99,101,109,119,121,131,133,152,0,0),  {vul,nv}
        (60,63,64,65,66,67,68,69,71,72,73,75,79,85,143,144),     {nv,vul}
        (40,92,94,98,99,101,109,119,121,131,133,152,0,0,0,0));   {vul,vul}
const
    vulname       : Array[1..4] of String[4] = ('NONE','N-S ','E-W ','BOTH');
const
     {direction names for individual}
    ind_dir       : Array[1..ACBL_MaxDirection] of String[6] =
                  ('NORTH ','EAST ','SOUTH ','WEST ');
const
     {direction names for pair}
    pair_dir      : Array[1..2] of String[4] = ('N-S ','E-W ');
const
     {parent check status for game file writes}
    CheckParent   : boolean = true;
const
     {name of instant matchpoint scoring table}
    InstantName   = 'INSTANT.MPS';
const
     {name of predetermined IMPs scoring table}
    PdimpName   = 'INSTANT.IMP';
const
     {name of predetermined BAM scoring table}
    PdBamName   = 'INSTANT.BAM';

const
    colorattr     : array[1..6] of byte = (15,15,15,15,15,15);
const
    {current event number}
    EventNo      : byte = 1;
const
     {game type names}
    gtText       : Array[0..4] of String[11] =
                  ('Pairs','Teams','Individual','Special Prs',
                   'B-A-M'{,'Team-2-Pair'});
const
    months      : Array[1..12] of String[9] =
                ('January','February','March','April','May','June','July',
                 'August','September','October','November','December');
const
     week_days  : Array[0..6] of String[9] =
                ('Sunday','Monday','Tuesday','Wednesday','Thursday',
                 'Friday','Saturday');
const
    day_time    : Array[0..2] of String[5] = (' Morn',' Aft',' Eve');

const
     QAsked     : boolean = false;

const
   Matches      : PMatches      = nil;
   MatchIndex   : PMatchIndex   = nil;
   SwissTables  : PSwissTables  = nil;
   VPTable      : PVPTable      = nil;
*/

/* From Pascal scorevar.h */
/*
    TGameType    = (gtPair,     {0=pairs}
                    gtTeam,     {1=teams - swiss, round robin, knockout}
                    gtInd,      {2=individual}
                    gtHS,       {3=home style pairs, continuous pairs final}
                    gtBAM);     {4=board-a-match teams}
                    {gtT2P);     {teams of two pairs}
*/


#ifdef MAIN
char *ACBL_TEXT_tgame_type[] = {
		"Pairs (0)",
		"Teams (1) - Swiss/Round Robin/KOs",
		"Individual (2)",
		"Home style pairs (3)",
		"BAM (4)"};

char *ACBL_TEXT_sgame_type[] = {
		"Pairs",
		"Teams - Swiss/Round Robin/KOs",
		"Individual",
		"Home style pairs",
		"BAM"};
#else
extern char *ACBL_TEXT_tgame_type[];
extern char *ACBL_TEXT_sgame_type[];
#endif


/* From mtables.pas - line 567 */
#ifdef MAIN
char *ACBL_TEXT_RatingText[] = {
                 "No game / Unsanctioned",
                 "Club Masterpoint",
                 "Club Championship",
                 "Charity Club Championship",
                 "Unit Championship",
                 "Sectional",
                 "Regional",
                 "Club International Fund",
                 "Club ACBL Membership",
                 "GNT / NAP",
                 "CNTC / COPC / CWTC",
                 "Fund raiser (other)",
                 "Upgraded Club Championship",
                 "National",
                 "STAC",
                 "Bridge Plus",
                 "Club MPs for recording",
                 "Progressive Sectional",
                 "Unit Charity",
                 "Annual Unit extended team",
                 "North American Pairs - Club",
                 "North American Pairs - Unit",
                 "Grand National Teams - Club",
                 "Grand National Teams - Unit",
                 "ACBL wide Charity",
                 "ACBL wide International Fund",
                 "District Charity",
                 "Canada Wide Olympiad Fund",
                 "WorldWide matchpoint",
                 "ACBL Wide instant matchpoint",
                 "Junior Fund",
                 "Member / Guest",
                 "ACBL Wide Senior",
                 "COPC - Club",
                 "CNTC - Master / Non-master",
                 "CNTC - Club",
                 "CNTC - Unit",
                 "CWTC",
                 "Canada Rookie / Master",
                 "Inter Club Championship",
                 "Unit-wide Championship",
                 "North American 49er Pairs",
                 "Super Club Championship",
                 "Club Appreciation game",
                 "ACBL wide Charity: no hands",
                 "ACBL wide Intl Fund: no hands",
                 "WorldWide Simultaneous Charity",
                 "Pupil Game",
                 "Introductory Game",
                 "Club Appreciation Team game",
                 "NABC Promotional game",
                 "GNT Fund raiser",
                 "CNTC Fund raiser",
                 "ACBL/District rankings",
                 "ACBL Bridge Week",
                 "Club Education Foundation",
                 "Unit International Fund",
                 "Unit Junior Fund",
                 "Unit Education Foundation",
                 "District International Fund",
                 "District Junior Fund",
                 "District Education Foundation",
                 "CBF Simultaneous Pairs",
								 "Grass Roots Fund",
								 "64",
	};
#else
extern char *ACBL_TEXT_RatingText[];
#endif


     /* masterpoint rating text for tourn mode game file */
#ifdef MAIN
char *ACBL_TEXT_Tourn_rating_text[] = {
                        "4  Unit Championship",
                        "5  Sectional",
                        "6  Regional",
                        "9  GNT / NAP",
                        "10 CNTC / COPC / CWTC (Canada)",
                        "13 National",
                        "14 STAC Final Results",
                        "17 Progressive Sectional Final",
                        "1  Club Masterpoint",
                        "2  Club Championship",
                        "39 Inter Club Championship Final Results",
                        "40 Unit Wide Championship Final Results",
	};
/*
                        {$ifdef office}
                        "53 ACBL/District rankings",
                        {$endif}
                        "0  No masterpoints"
*/
#else
extern char *ACBL_TEXT_Tourn_rating_text[];
#endif

#ifdef MAIN
char *ACBL_TEXT_board_vulnerability[] = {
	"EW", 	// 0	 - same as board 16, 32 etc.
	"None", // 1
	"NS", // 2
	"EW", // 3
	"Both", // 4
	"NS", // 5
	"EW", // 6
	"Both", // 7
	"None", // 8
	"EW", // 9
	"Both", // 10
	"None", // 11
	"NS", // 12
	"Both", // 13
	"None", // 14
	"NS", // 15
	"EW", // 16 - Repeats from here...
	"None", // 17
	"NS", // 18
	"EW", // 19
	"Both", // 20
	"NS", // 21
	"EW", // 22
	"Both", // 23
	"None", // 24
	"EW", // 25
	"Both", // 26
	"None", // 27
	"NS", // 28
	"Both", // 29
	"None", // 30
	"NS", // 31
	"EW" // 32
};
#else
extern char *ACBL_TEXT_board_vulnerability [];
#endif

// These are new constants
// Define a number to indicate a board not played
#define NO_SUCH_RESULT 99999

// Options for opt-y
#define ACBL_XML_DO_NOT_PRINT_INDENT 0x1
#define ACBL_XML_PRINT_ALL_VALUES 0x2
#define ACBL_XML_PRINT_ALL_FIELDS 0x4
#define ACBL_XML_PRINT_COMMENTS 0x8
#define ACBL_XML_WRITE_FILE_STDOUT 0x10
// #define ACBL_XML_PRINT_OFFSETS 0x20

// Defines to print a comment
#define PALL_VALUES (opt_y & ACBL_XML_PRINT_ALL_VALUES)
#define PALL_FIELDS (opt_y & ACBL_XML_PRINT_ALL_FIELDS)
// #define PALL_OFFSETS (opt_y & ACBL_XML_PRINT_OFFSETS)
#define PCOM (opt_y & ACBL_XML_PRINT_COMMENTS)

#ifdef MAIN
char *ACBL_TEXT_board_dealer[] = {
	"W", // 0
	"N", // 1
	"E", // 2
	"S", // 3
	"W", // 4
};

char *ACBL_TEXT_smptype[] = {
	"PreviousSession",
	"ThisSession",
	"Event", };

char *ACBL_TEXT_months[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};
#else
extern char *ACBL_TEXT_board_dealer [];
extern char *ACBL_TEXT_smptype [];
extern char *ACBL_TEXT_months [];
#endif


// Event Ratings
// See mpdef.pas
// The lower case version matches the same spelling as the original ACBLscore.
// Preferred version for new code is the all upper case version that follows
#define ACBL_EVENT_RATING_None        0 // no masterpoints
#define ACBL_EVENT_RATING_NO_MASTERPOINTS        0 // no masterpoints
#define ACBL_EVENT_RATING_RP          1 // club masterpoint
#define ACBL_EVENT_RATING_CLUB_MASTERPOINT          1 // club masterpoint
#define ACBL_EVENT_RATING_CC          2 // club championship
#define ACBL_EVENT_RATING_CLUB_CHAMPIONSHIP          2 // club championship
#define ACBL_EVENT_RATING_CCh         3 // club charity championship
#define ACBL_EVENT_RATING_CLUB_CHARITY_CHAMPIONSHIP         3 // club charity championship
#define ACBL_EVENT_RATING_Unit        4 // unit championship
#define ACBL_EVENT_RATING_UNIT_CHAMPIONSHIP        4 // unit championship
#define ACBL_EVENT_RATING_Sect        5 // sectional
#define ACBL_EVENT_RATING_SECTIONAL        5 // sectional
#define ACBL_EVENT_RATING_Reg         6 // regional
#define ACBL_EVENT_RATING_REGIONAL         6 // regional
#define ACBL_EVENT_RATING_Int         7 // club international fund
#define ACBL_EVENT_RATING_CLUB_INTERNATIONAL_FUND         7 // club international fund
#define ACBL_EVENT_RATING_Mem         8 // club membership
#define ACBL_EVENT_RATING_CLUB_MEMBERSHIP         8 // club membership
#define ACBL_EVENT_RATING_NAP         9 // north am pairs, grand nat teams - not used
#define ACBL_EVENT_RATING_NAP_GNT_NOT_USED         9 // north am pairs, grand nat teams - not used
#define ACBL_EVENT_RATING_COP        10 // canadian CNTC, COPC, CWTC - not used
#define ACBL_EVENT_RATING_CANADIAN_CNTC_COPC_CWTC_NOT_USED        10 // canadian CNTC, COPC, CWTC - not used
#define ACBL_EVENT_RATING_Fund       11 // Other Fund game - not used
#define ACBL_EVENT_RATING_OTHER_FUND_GAME_NOT_USED       11 // Other Fund game - not used
#define ACBL_EVENT_RATING_UCC        12 // upgraded club championship
#define ACBL_EVENT_RATING_UPGRADED_CLUB_CHAMPIONSHIP        12 // upgraded club championship
#define ACBL_EVENT_RATING_Nat        13 // national
#define ACBL_EVENT_RATING_NATIONAL        13 // national
#define ACBL_EVENT_RATING_STAC       14 // sectional tournament at clubs
#define ACBL_EVENT_RATING_STAC       14 // sectional tournament at clubs
#define ACBL_EVENT_RATING_BP         15 // bridge plus
#define ACBL_EVENT_RATING_BRIDGE_PLUS         15 // bridge plus
#define ACBL_EVENT_RATING_RPrec      16 // club mps reported by club - only for monthly report
#define ACBL_EVENT_RATING_CLUB_MPS_REPORTED_BY_CLUBS      16 // club mps reported by club - only for monthly report
#define ACBL_EVENT_RATING_ProgSect   17 // Progressive sectional
#define ACBL_EVENT_RATING_PROGRESSIVE_SECTIONAL   17 // Progressive sectional
#define ACBL_EVENT_RATING_UnitC      18 // Unit charity
#define ACBL_EVENT_RATING_UNIT_CHARITY      18 // Unit charity
#define ACBL_EVENT_RATING_UnitExt    19 // annual unit extended team game
#define ACBL_EVENT_RATING_ANNUAL_UNIT_EXTENDED_TEAM_GAME    19 // annual unit extended team game
#define ACBL_EVENT_RATING_NAPc       20 // NAP club level
#define ACBL_EVENT_RATING_NAP_CLUB_LEVEL       20 // NAP club level
#define ACBL_EVENT_RATING_NAPu       21 // NAP unit level
#define ACBL_EVENT_RATING_NAP_UNIT_LEVEL       21 // NAP unit level
#define ACBL_EVENT_RATING_GNTc       22 // GNT club level
#define ACBL_EVENT_RATING_GNT_CLUB_LEVEL       22 // GNT club level
#define ACBL_EVENT_RATING_GNTu       23 // GNT unit level
#define ACBL_EVENT_RATING_GNT_UNIT_LEVEL       23 // GNT unit level
#define ACBL_EVENT_RATING_AwideC     24 // ACBL wide charity
#define ACBL_EVENT_RATING_ACBL_WIDE_CHARITY     24 // ACBL wide charity
#define ACBL_EVENT_RATING_AwideI     25 // ACBL wide int. fund
#define ACBL_EVENT_RATING_ACBL_WIDE_INTERNATIONAL_FUND     25 // ACBL wide int. fund
#define ACBL_EVENT_RATING_DistC      26 // District Charity
#define ACBL_EVENT_RATING_DISTRICT_CHARITY      26 // District Charity
#define ACBL_EVENT_RATING_CwideO     27 // Canada wide Olympiad fund
#define ACBL_EVENT_RATING_CANADA_WIDE_OLYMPIAD_FUND     27 // Canada wide Olympiad fund
#define ACBL_EVENT_RATING_WwideInst  28 // World wide instant mp
#define ACBL_EVENT_RATING_WORLD_WIDE_INSTANT_MP  28 // World wide instant mp
#define ACBL_EVENT_RATING_AwideInst  29 // ACBL wide instant mp
#define ACBL_EVENT_RATING_ACBL_WIDE_INSTANT_MP  29 // ACBL wide instant mp
#define ACBL_EVENT_RATING_Junior     30 // Junior fund
#define ACBL_EVENT_RATING_JUNIOR_FUND     30 // Junior fund
#define ACBL_EVENT_RATING_MemGuestx  31 // Club member / guest - defunct
#define ACBL_EVENT_RATING_CLUB_MEMBER_GUEST_NOT_USED  31 // Club member / guest - defunct
#define ACBL_EVENT_RATING_AwideS     32 // ACBL wide senior
#define ACBL_EVENT_RATING_ACBL_WIDE_SENIOR     32 // ACBL wide senior
#define ACBL_EVENT_RATING_COPCc      33 // COPC club level
#define ACBL_EVENT_RATING_COPC_CLUB_LEVEL      33 // COPC club level
#define ACBL_EVENT_RATING_CNTCMNc    34 // CNTC Master/non master club level
#define ACBL_EVENT_RATING_CNT_MASTER_NM_CLUB_LEVEL    34 // CNTC Master/non master club level
#define ACBL_EVENT_RATING_CNTCC      35 // CNTC club level
#define ACBL_EVENT_RATING_CNTC_CLUB_LEVEL      35 // CNTC club level
#define ACBL_EVENT_RATING_CNTCU      36 // CNTC unit level
#define ACBL_EVENT_RATING_CNTC_UNIT_LEVEL      36 // CNTC unit level
#define ACBL_EVENT_RATING_CWTC       37 // CWTC
#define ACBL_EVENT_RATING_CWTC       37 // CWTC
#define ACBL_EVENT_RATING_CanRookie  38 // Canada rookie / master
#define ACBL_EVENT_RATING_CANADA_ROOKIE_MASTER  38 // Canada rookie / master
#define ACBL_EVENT_RATING_CCM        39 // Multi - site club champ
#define ACBL_EVENT_RATING_MULTI_SITE_CLUB_CHAMPIONSHIP        39 // Multi - site club champ
#define ACBL_EVENT_RATING_Uwide      40 // Unit wide championship
#define ACBL_EVENT_RATING_UNIT_WIDE_CHAMPIONSHIP      40 // Unit wide championship
#define ACBL_EVENT_RATING_NAP49      41 // NAP 49er pairs
#define ACBL_EVENT_RATING_NAP_49ER_PAIRS      41 // NAP 49er pairs
#define ACBL_EVENT_RATING_SCC        42 // Super Club Championship - defunct
#define ACBL_EVENT_RATING_SUPER_CLUB_CHAMPIONSHIP_NOT_USED        42 // Super Club Championship - defunct
#define ACBL_EVENT_RATING_ClubA      43 // Club appreciation game
#define ACBL_EVENT_RATING_CLUB_APPRECIATION_GAME      43 // Club appreciation game
#define ACBL_EVENT_RATING_AwideCnx   44 // ACBL wide charity - no hand records - defunct
#define ACBL_EVENT_RATING_ACBL_WIDE_CHARITY_NO_HAND_RECORDS_NOT_USED   44 // ACBL wide charity - no hand records - defunct
#define ACBL_EVENT_RATING_AwideInx   45 // ACBL wide int. fund - no hand records - defunct
#define ACBL_EVENT_RATING_ACBL_WIDE_INTERNATIONAL_FUND_NO_HAND_RECORDS_NOT_USED   45 // ACBL wide int. fund - no hand records - defunct
#define ACBL_EVENT_RATING_WwideChx   46 // WorldWide Simultaneous Charity - defunct
#define ACBL_EVENT_RATING_WORLD_WIDE_SIMULTANEOUS_CHARITY_NOT_USED   46 // WorldWide Simultaneous Charity - defunct
#define ACBL_EVENT_RATING_Pupil      47 // Pupil
#define ACBL_EVENT_RATING_PUPIL      47 // Pupil
#define ACBL_EVENT_RATING_Intro      48 // Introductory
#define ACBL_EVENT_RATING_INTRODUCTORY      48 // Introductory
#define ACBL_EVENT_RATING_ClubAT     49 // Club appreciation team game
#define ACBL_EVENT_RATING_CLUB_APPRECIATION_TEAM_GAME     49 // Club appreciation team game
#define ACBL_EVENT_RATING_NABCF      50 // NABC fund raiser
#define ACBL_EVENT_RATING_NABC_FUND_RAISER      50 // NABC fund raiser
#define ACBL_EVENT_RATING_GNTF       51 // GNT fund raiser
#define ACBL_EVENT_RATING_GNT_FUND_RAISER       51 // GNT fund raiser
#define ACBL_EVENT_RATING_CNTCF      52 // CNTC fund raiser
#define ACBL_EVENT_RATING_CNTC_FUND_RAISER      52 // CNTC fund raiser
#define ACBL_EVENT_RATING_AwideRank  53 // ACBL/district wide rankings - only at the office
#define ACBL_EVENT_RATING_ACBL_DISTRICT_WIDE_RANKINGS  53 // ACBL/district wide rankings - only at the office
#define ACBL_EVENT_RATING_ACBLBW     54 // ACBL Bridge week
#define ACBL_EVENT_RATING_ACBL_BRIDGE_WEEK     54 // ACBL Bridge week
#define ACBL_EVENT_RATING_EdFund     55 // ACBL Education Fund
#define ACBL_EVENT_RATING_ACBL_EDUCATION_FUND     55 // ACBL Education Fund
#define ACBL_EVENT_RATING_UnitI      56 // Unit International Fund
#define ACBL_EVENT_RATING_UNIT_INTERNATIONAL_FUND      56 // Unit International Fund
#define ACBL_EVENT_RATING_UnitJ      57 // Unit Junior Fund
#define ACBL_EVENT_RATING_UNIT_JUNIOR_FUND      57 // Unit Junior Fund
#define ACBL_EVENT_RATING_UnitE      58 // Unit Education Fund
#define ACBL_EVENT_RATING_UNIT_EDUCATION_FUND      58 // Unit Education Fund
#define ACBL_EVENT_RATING_DistI      59 // District International Fund
#define ACBL_EVENT_RATING_DISTRICT_INTERNATIONAL_FUND      59 // District International Fund
#define ACBL_EVENT_RATING_DistJ      60 // District Junior Fund
#define ACBL_EVENT_RATING_DISTRICT_JUNIOR_FUND      60 // District Junior Fund
#define ACBL_EVENT_RATING_DistE      61 // District Education Fund
#define ACBL_EVENT_RATING_DISTRICT_EDUCATION_FUND      61 // District Education Fund
#define ACBL_EVENT_RATING_CSimP      62 // CBF Simultaneous Pairs
#define ACBL_EVENT_RATING_CBF_SIMULTANEOUS_PAIRS      62 // CBF Simultaneous Pairs

// Game Types
// See mpdef.pas
// The lower case version matches the same spelling as the original ACBLscore.
// Preferred version for new code is the all upper case version that follows

// Type of event is used for masterpoint calculation
#define ACBL_TYPE_OF_EVENT_MIN 1
#define ACBL_TYPE_OF_EVENT_INDIVIDUAL 1
#define ACBL_TYPE_OF_EVENT_PAIR 2
#define ACBL_TYPE_OF_EVENT_KO 3
#define ACBL_TYPE_OF_EVENT_SWISS_TEAM 4
#define ACBL_TYPE_OF_EVENT_BAM 5
#define ACBL_TYPE_OF_EVENT_MAX 5

#endif /* __ACBL_CONSTANTS_H__ */
