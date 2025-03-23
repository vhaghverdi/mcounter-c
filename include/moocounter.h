#pragma once

#include <stdbool.h>

typedef struct MooCounter *MooCounter;

struct MooCounter {
	// destructor
	void (*free)(MooCounter *self);

	// accessors
	int (*count)(MooCounter self);
	bool (*error)(MooCounter self);

	// mutators
	int (*add_1)(MooCounter self);
	int (*add_10)(MooCounter self);
	int (*add_100)(MooCounter self);
	int (*add_1000)(MooCounter self);
	int (*reset)(MooCounter self); // reset count, clear error

	// utility
	void (*print)(MooCounter self);

	int _count; // range: [0, 9999] (if error: -9999)
	bool _error;
};

MooCounter mooc_new(); // default constructor
MooCounter mooc_new_n(int n); // constructor with argument
