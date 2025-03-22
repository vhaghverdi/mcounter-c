#pragma once

#include <stdbool.h>

typedef struct MCounter *MCounter; // opaque type

MCounter mc_new(); // default constructor
MCounter mc_new_n(int n); // constructor with argument
void mc_free(MCounter *mc); // destructor

// accessors
int mc_count(MCounter mc);
bool mc_error(MCounter mc);

// mutators
int mc_add_1(MCounter mc);
int mc_add_10(MCounter mc);
int mc_add_100(MCounter mc);
int mc_add_1000(MCounter mc);
int mc_reset(MCounter mc); // reset count, clear error

// utility
void mc_print(MCounter mc);

// private functions
static int mc_add(MCounter mc, int n);
static bool mc_is_error(MCounter mc);
