#pragma once

#include <stdbool.h>

typedef struct MCounter *MCounter;

// PUBLIC INTERFACE

// Create a new MCounter object.
MCounter mc_new();

// Free mc and set to NULL.
void mc_free(MCounter *mc);

static int mc_add(MCounter mc, int n); // THIS FUNCTION IS PRIVATE
int mc_add_1(MCounter mc);
int mc_add_10(MCounter mc);
int mc_add_100(MCounter mc);
int mc_add_1000(MCounter mc);

// Reset counter to 0 (and clear error).
int mc_reset(MCounter mc);

// Return current count.
int mc_count(MCounter mc);

// Return error status.
bool mc_error(MCounter mc);
