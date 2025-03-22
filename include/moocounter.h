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
static void mooc_free(MooCounter *mc);

static int mooc_count(MooCounter mc);
static bool mooc_error(MooCounter mc);

static int mooc_add_1(MooCounter mc);
static int mooc_add_10(MooCounter mc);
static int mooc_add_100(MooCounter mc);
static int mooc_add_1000(MooCounter mc);
static int mooc_reset(MooCounter mc);

static void mooc_print(MooCounter mc);

// private functions
static int mooc_add(MooCounter mc, int n);
static bool mooc_is_error(MooCounter mc);
