#ifndef __ACBLSP_MITCHELL_DETAIL_H__
#define __ACBLSP_MITCHELL_DETAIL_H__ 1
/*=========================================================================
  MitchellDetail.h

    * Mitchell Movement:
      - Compute Detail of Movement
      - includes Simple:  Skip
      - missing  Simple:  ByeStand & Relay features
    * Version 0.5

  Thomas M. Eidson
  July, 2012

  Copyright (c) 2012, Hammond Software, Inc.
  =========================================================================*/
#include <iostream>
#include "inc/acblsp_movement.h"
#include "MovementError.h"
#include "Mitchell.h"

// ========================
class MitchellDetail
{
  private:

// Internal Data

   int Tables, Rounds;
   int Boards, BoardsPerSet, BoardsPlayedMax, BoardSets;
   int StartTable, StartMovePair, StartMoveTable;
   int SkipRound; 
   int Byestand;
   int PhantomPair, PhantomNS;
   int AnchorPairs, MovePairs;

// Control

   bool Error;
   bool doSkip;

// Movement Data

   struct movement *Move;
   int **Boardset;
   int *AnchorPair;
   int **MovePair;

// ------------------------
  public:
   MitchellDetail(struct movement *move);
   ~MitchellDetail();
   void create();
   int** getBoardset();
   int*  getAnchorPair();
   int** getMovePair();
   bool testError();
};
#endif /* __ACBLSP_MITCHELL_DETAILH__ */

