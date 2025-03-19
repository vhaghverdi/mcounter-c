#include <stdlib.h>

#include "../inc/mcounter.h"

// PRIVATE IMPLEMENTATION

struct MCounter {
	int count;
	bool error;
};

MCounter mc_new()
{
	MCounter mc = malloc(sizeof(*mc));
	mc->count = 0;
	mc->error = false;
	return mc;
}

void mc_free(MCounter *mc)
{
	if (mc && *mc) {
		free(*mc);
		*mc = NULL;
	}
}

int mc_add(MCounter mc, int n)
{
	if (mc_error(mc))
		return mc_count(mc);

	mc->count += n;

	if (mc->count > 9999) {
		mc->error = true;
		mc->count = -9999;
	}

	return mc_count(mc);
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

int mc_count(MCounter mc)
{
	return mc->count;
}

bool mc_error(MCounter mc)
{
	return mc->error;
}
