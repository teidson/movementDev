#ifndef __ACBLSP_CONTROL_H__
#define __ACBLSP_CONTROL_H__ 1

// This file defines the control structure used by all the interfaces
// between Ruby and C

// I have no idea how this structure will develop
// It will be used by all connections from Ruby <-> C
// Defining the fact that the system will have this structure helps

// If defined, 
struct acblsp_control
{
	int ac_option;	// What to do with the structure
  int ac_debug; // Possibly used for debug values. May be unique for each struct
  int ac_counter;  // May need some statistical counters
		// More fields probably added later
};

#endif /* __ACBLSP_CONTROL_H__ */
