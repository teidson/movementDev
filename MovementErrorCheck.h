#ifndef __ACBLSP_MOVEMENT_ERROR_CHECK_H__
#define __ACBLSP_MOVEMENT_ERROR_CHECK_H__ 1
/*=========================================================================
  MovementErrorCheck.h

    * Bridge Game Movement:  Test Movement Structure
                             . values in correct ranges
                             . consistancy
    * Version 0.5

  Thomas M. Eidson
  February, 2013

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include <iostream>
#include "inc/acblsp_movement.h"
#include "./acblsp_control.h"
#include "MovementError.h"
#include "Mitchell.h"

// ========================
class MovementErrorCheck
{
  private:

   int tableMax, roundMax, lineMax;
   int arrayMax;
   int arraySize;
   int Boards, BoardsPerSet, BoardsPlayedMax;
   bool Error;

// Movement Data

   struct movement *Move;

// Internal Toolkit

   bool check_is_valid(int ival, int imin, int imax, int ierr);
   bool is_pairs();
   bool is_ind();
// ------------------------
  public:
   MovementErrorCheck(struct movement *move);
   void movement_error_check();
};
#endif /* __ACBLSP_MOVEMENT_ERROR_CHECK_H__ */

