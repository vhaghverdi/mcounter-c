#include <stdio.h>
#include <stdlib.h>

#include "../inc/moocounter.h"

const char *str_true = "true";
const char *str_false = "false";

const char *bool_to_str(bool flag)
{
	return flag ? str_true : str_false;
}

int main(void)
{
	MooCounter mc = mc_new();

	printf("count after add 1:     %d\n", mc->add_1(mc));
	printf("count after add 10:    %d\n", mc->add_10(mc));
	printf("count after add 100:   %d\n", mc->add_100(mc));
	printf("count after add 1000:  %d\n", mc->add_1000(mc));
	printf("count: %d\n", mc->count(mc));

	if (mc->error(mc))
		puts("an error occured:");
	else
		puts("no error yet");

	printf("error state: %s\n\n", bool_to_str(mc->error(mc)));

	for (int i = 0; i < 20 && !mc->error(mc); i++) {
		printf("adding another 1000: %d\n", mc->add_1000(mc));
		if (mc->error(mc))
			puts("an error occured:");
		else
			puts("no error yet");
	}

	printf("\nerror state: %s\n", bool_to_str(mc->error(mc)));
	printf("adding another 1000: %d\n", mc->add_1000(mc));
	mc->reset(mc);
	printf("\ncounter reset: %d\n", mc->count(mc));
	printf("error state: %s\n", bool_to_str(mc->error(mc)));
	puts("\n\n--------------- D O N E ---------------\n");

	mc->free(&mc);

	if (mc)
		puts("Counter was supposed to be set to NULL.");
	else
		puts("Counter successfully freed.");

	return EXIT_SUCCESS;
}
