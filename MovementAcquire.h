#ifndef __ACBLSP_MOVEMENT_ACQUIRE_H__
#define __ACBLSP_MOVEMENT_ACQUIRE_H__ 1
/*=========================================================================
  MovementAcquire.h

    * Bridge Game Movement:  Acquire data
    * Version 0.5

  Thomas M. Eidson
  February, 2013

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include <iostream>
#include "inc/acblsp_movement.h"
#include "MovementError.h"
#include "Mitchell.h"
#include "MitchellDetail.h"
using namespace std;

// ========================
class MovementAcquire
{
  private:

   int tableMax;
   int roundMax;
   int lineMax;
   int arrayMax;
   int arraySize;

// Control

   bool Error;

// Movement Data

   struct movement *Move;
   int **Boardset;
   int *AnchorPair;
   int **MovePair;

// Mitchell Toolkit

   MitchellDetail *detail;

// ------------------------
  public:
   MovementAcquire(struct movement *move);
   ~MovementAcquire();
   void computeMitchell();
   void createMovement();
   bool testError();
};
#endif /* __ACBLSP_MOVEMENT_ACQUIRE_H__ */

