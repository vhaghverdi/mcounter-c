#include <stdlib.h>

#include "../inc/moocounter.h"

// PRIVATE IMPLEMENTATION

MooCounter mc_new()
{
	MooCounter mc = calloc(1, sizeof(*mc));

	mc->_count = 0;
	mc->_error = false;

	mc->add_1 = mc_add_1;
	mc->add_10 = mc_add_10;
	mc->add_100 = mc_add_100;
	mc->add_1000 = mc_add_1000;

	mc->reset = mc_reset;
	mc->count = mc_count;
	mc->error = mc_error;

	mc->free = mc_free;

	return mc;
}

void mc_free(MooCounter *mc)
{
	if (mc && *mc) {
		free(*mc);
		*mc = NULL;
	}
}

int mc_add(MooCounter mc, int n)
{
	if (mc_error(mc))
		return mc_count(mc);

	mc->_count += n;

	if (mc->_count > 9999) {
		mc->_error = true;
		mc->_count = -9999;
	}

	return mc_count(mc);
}

int mc_add_1(MooCounter mc)
{
	return mc_add(mc, 1);
}

int mc_add_10(MooCounter mc)
{
	return mc_add(mc, 10);
}

int mc_add_100(MooCounter mc)
{
	return mc_add(mc, 100);
}

int mc_add_1000(MooCounter mc)
{
	return mc_add(mc, 1000);
}

int mc_reset(MooCounter mc)
{
	mc->_error = false;
	mc->_count = 0;
	return mc->_count;
}

int mc_count(MooCounter mc)
{
	return mc->_count;
}

bool mc_error(MooCounter mc)
{
	return mc->_error;
}
