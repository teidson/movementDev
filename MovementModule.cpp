/*
 * Copyright 2012-2013 Hammond Software
 *
 * Movement_module.cc
 *
 * Helper set of routines to calculate movements
 *
 * Code passes a structure between a shared library and the calling code
 * If you make changes to the structure MUST make same change on both sides!
 *
 * Internally uses a 1 dimensional array to hold the 3 dimensional movement array
 *
 */
#include <iostream>
#include "MovementAcquire.h"
#include "MovementErrorCheck.h"
using namespace std;

extern "C" void Movement_function(struct movement *movep)
{
  MovementAcquire acquire(movep);
  MovementErrorCheck check(movep);

  int debug = 0;
// ........................
// Initialize Movement Structure

  movep->movement_error = ACBLSP_MOVEMENT_ERROR_NOT_READY;

// Setup Debug (TBD)
//  if (debug_level & DEBUG_ENTER_ROUTINE)
//  {  printf("Entering %s\n", routine_name); }

// Test Control Function (TBD)
// no control function -> an error
//   if (movep->movement_controlp == (struct acblsp_control *) NULL)
//   {
//     movep->movement_error = 33333;
//     return;
//   }

// Function:  Initialize structure (if requested)

  if ( movep->movement_function == ACBLSP_MOVEMENT_FUNCTION_INIT_STRUCTURE )
  {
cerr << endl;
cerr << "Debug:  Initialize Structure" << endl;
cerr << endl;
//    movement_init(movep, 0);
    return;
  }

// Set Debug (TBD)
//   debug = movep->movement_controlp->ac_debug;

// Function:  Validate Structure (always)
// Note:  return if not validated

  check.movement_error_check();
cerr << endl;
cerr << "Debug:  Check Structure Always" << endl;
cerr << endl;

//  printf("error=%d\n", movep->movement_error);
  if (movep->movement_error != ACBLSP_MOVEMENT_ERROR_READY)
  {
    return;
  }

// Execute Target (primary) Function

   switch( movep->movement_function )
   {
    case ACBLSP_MOVEMENT_FUNCTION_CALCULATE_MOVEMENT:
cerr << endl;
cerr << "Debug:  Calculate Movement" << endl;
cerr << endl;
     acquire.computeMitchell();
     if (! acquire.testError()) 
     {
       acquire.createMovement();
     }
     break;

// TBD
    case ACBLSP_MOVEMENT_FUNCTION_PRINT_STRUCTURE:
cerr << endl;
cerr << "Debug:  Print Structure" << endl;
cerr << endl;
//   movement_print_structure(movep);
     break;

// TBD: 
    case ACBLSP_MOVEMENT_FUNCTION_TEST_STRUCTURE:
cerr << endl;
cerr << "Debug:  Test Structure" << endl;
cerr << endl;
//   movement_init(movep, 1);
     break;

// TBD:  redundant
//       default added:  OK??

    case ACBLSP_MOVEMENT_FUNCTION_CHECK_STRUCTURE:
    default:
cerr << endl;
cerr << "Debug:  Check Structure Fake" << endl;
cerr << endl;
//     check.movement_error_check();
     break;
  }
} 

