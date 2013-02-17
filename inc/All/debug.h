// Copyright 2012 Hammond Software
#ifndef __DEBUG_H__
#define __DEBUG_H__ 1


/* Globals */
EXTERN FILE *dbg_file;
	// Assume debug is always on, can be overridden with -d option 
EXTERN int debug_level;


// Various debug options
	// 1
#define DEBUG_PRINT_ALL_DATA							0x1
#define DEBUG_PRINT_SAFETY_CHECKS					0x20000
#define DEBUG_PRINT_SECTION_DETAIL				0x4
#define DEBUG_PRINT_EVENT_DETAIL					0x8
#define DEBUG_PRINT_STRUCTURE 						0x10
#define DEBUG_PRINT_ENTER_ROUTINES 				0x20
#define DEBUG_PRINT_XML 									0x40
#define DEBUG_PRINT_PROFILE 							0x80

	// 256 = 0x100
#define DEBUG_PRINT_MEMORY 								0x100
#define DEBUG_PRINT_ENTIRE_FILE 					0x200
	// 1024 (2^10)
#define DEBUG_PRINT_FAROUT 								0x400
	// 2048 = 0x800
#define DEBUG_PRINT_I_WHEN_COPYING 				0x800
#define DEBUG_PRINT_RUBY 									0x1000						

#define DEBUG_ENTER_ROUTINE		0x2000
#define DEBUG_LEAVE_ROUTINE		0x4000

#define DEBUG_WRITE_FILL_VALUE 0x2
#endif /* __ACBL_DEBUG__ */

