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
#include <stdio.h>
#include "inc/acblsp_movement.h"

void Movement_function(struct movement *move);

int movement_function(struct movement *move)
{
// ........................
  Movement_function(move);
}
