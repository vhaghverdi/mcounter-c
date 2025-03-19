#pragma once

#include <stdbool.h>

// PUBLIC INTERFACE

typedef struct MooCounter *MooCounter;

struct MooCounter {
	int (*add_1)(MooCounter self);
	int (*add_10)(MooCounter self);
	int (*add_100)(MooCounter self);
	int (*add_1000)(MooCounter self);
	int (*reset)(MooCounter self);
	int (*count)(MooCounter self);
	bool (*error)(MooCounter self);
	void (*free)(MooCounter *self);

	int _count;
	bool _error;
};

// Create a new MooCounter object.
MooCounter mc_new();

// Free mc and set to NULL.
static void mc_free(MooCounter *mc);

static int mc_add(MooCounter mc, int n);
static int mc_add_1(MooCounter mc);
static int mc_add_10(MooCounter mc);
static int mc_add_100(MooCounter mc);
static int mc_add_1000(MooCounter mc);

// Reset counter to 0 (and clear error).
static int mc_reset(MooCounter mc);

// Return current count.
static int mc_count(MooCounter mc);

// Return error status.
static bool mc_error(MooCounter mc);
