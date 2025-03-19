#include <stdio.h>
#include <stdlib.h>

#include "mcounter.h"

const char *str_true = "true";
const char *str_false = "false";

const char *bool_to_str(bool flag)
{
	return flag ? str_true : str_false;
}

int main(void)
{
	MCounter mc = mc_new();

	printf("count after add 1:     %d\n", mc_add_1(mc));
	printf("count after add 10:    %d\n", mc_add_10(mc));
	printf("count after add 100:   %d\n", mc_add_100(mc));
	printf("count after add 1000:  %d\n", mc_add_1000(mc));
	printf("count: %d\n", mc_count(mc));

	if (mc_error(mc))
		puts("an error occured:");
	else
		puts("no error yet");

	printf("error state: %s\n\n", bool_to_str(mc_error(mc)));

	for (int i = 0; i < 20 && !mc_error(mc); i++) {
		printf("adding another 1000: %d\n", mc_add_1000(mc));
		if (mc_error(mc))
			puts("an error occured:");
		else
			puts("no error yet");
	}

	printf("\nerror state: %s\n", bool_to_str(mc_error(mc)));
	printf("adding another 1000: %d\n", mc_add_1000(mc));
	mc_reset(mc);
	printf("\ncounter reset: %d\n", mc_count(mc));
	printf("error state: %s\n", bool_to_str(mc_error(mc)));
	puts("\n\n--------------- D O N E ---------------");

	mc_free(mc);

	return EXIT_SUCCESS;
}
