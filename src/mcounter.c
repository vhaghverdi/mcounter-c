#include "mcounter.h"
#include <stdio.h>
#include <stdlib.h>

static const int MAX_COUNT = 9999;
static const int ERR_COUNT = -9999;

// private functions
static int mc_add(MCounter mc, int n);
static bool mc_is_error(MCounter mc);

struct MCounter {
	int count; // range: [0, 9999] (if error: -9999)
	bool error;
};

MCounter mc_new()
{
	return mc_new_n(0);
}

MCounter mc_new_n(int n)
{
	MCounter mc = malloc(sizeof(*mc));
	if (mc == NULL) {
		fprintf(stderr, "Failed to allocate memory for MCounter.\n");
		exit(1);
	}
	mc->count = n;
	mc->error = mc_is_error(mc);
	return mc;
}

void mc_free(MCounter *mc)
{
	if (mc && *mc) {
		free(*mc);
		*mc = NULL;
	}
}

int mc_count(MCounter mc)
{
	return mc->count;
}

bool mc_error(MCounter mc)
{
	return mc->error;
}

int mc_add_1(MCounter mc)
{
	return mc_add(mc, 1);
}

int mc_add_10(MCounter mc)
{
	return mc_add(mc, 10);
}

int mc_add_100(MCounter mc)
{
	return mc_add(mc, 100);
}

int mc_add_1000(MCounter mc)
{
	return mc_add(mc, 1000);
}

int mc_reset(MCounter mc)
{
	mc->error = false;
	mc->count = 0;
	return mc->count;
}

void mc_print(MCounter mc)
{
	printf("-------\n|");
	if (mc->error)
		printf("ERROR");
	else
		printf(" %04d", mc->count);
	printf("|\n-------\n");
}

int mc_add(MCounter mc, int n)
{
	mc->count += n;
	mc->error = mc_is_error(mc);
	if (mc->error)
		mc->count = ERR_COUNT;
	return mc->count;
}

bool mc_is_error(MCounter mc)
{
	if ((mc->count > MAX_COUNT) || (mc->count < 0))
		return true;
	return false;
}
