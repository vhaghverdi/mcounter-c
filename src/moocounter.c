#include "moocounter.h"
#include <stdio.h>
#include <stdlib.h>

const int MAX_COUNT = 9999;
const int ERR_COUNT = -9999;

MooCounter mooc_new()
{
	return mooc_new_n(0);
}

MooCounter mooc_new_n(int n)
{
	MooCounter mc = malloc(sizeof(*mc));
	if (mc == NULL) {
		fprintf(stderr, "Failed to allocate memory for MooCounter.\n");
		exit(1);
	}

	mc->_count = n;
	mc->_error = mooc_is_error(mc);

	mc->count = mooc_count;
	mc->error = mooc_error;
	mc->add_1 = mooc_add_1;
	mc->add_10 = mooc_add_10;
	mc->add_100 = mooc_add_100;
	mc->add_1000 = mooc_add_1000;
	mc->reset = mooc_reset;
	mc->free = mooc_free;
	mc->print = mooc_print;

	return mc;
}

void mooc_free(MooCounter *mc)
{
	if (mc && *mc) {
		free(*mc);
		*mc = NULL;
	}
}

int mooc_count(MooCounter mc)
{
	return mc->_count;
}

bool mooc_error(MooCounter mc)
{
	return mc->_error;
}

int mooc_add_1(MooCounter mc)
{
	return mooc_add(mc, 1);
}

int mooc_add_10(MooCounter mc)
{
	return mooc_add(mc, 10);
}

int mooc_add_100(MooCounter mc)
{
	return mooc_add(mc, 100);
}

int mooc_add_1000(MooCounter mc)
{
	return mooc_add(mc, 1000);
}

int mooc_reset(MooCounter mc)
{
	mc->_error = false;
	mc->_count = 0;
	return mc->_count;
}

void mooc_print(MooCounter mc)
{
	printf("-------\n|");
	if (mc->_error)
		printf("ERROR");
	else
		printf(" %04d", mc->_count);
	printf("|\n-------\n");
}

int mooc_add(MooCounter mc, int n)
{
	mc->_count += n;
	mc->_error = mooc_is_error(mc);
	if (mc->_error)
		mc->_count = ERR_COUNT;
	return mc->_count;
}

bool mooc_is_error(MooCounter mc)
{
	if ((mc->_count > MAX_COUNT) || (mc->_count < 0))
		return true;
	return false;
}
