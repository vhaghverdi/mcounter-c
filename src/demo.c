#include "mcounter.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *prompt =
		"[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it  ";
	char input = 0;

	MCounter mc = mc_new();

	while (input != 'X' && input != 'x') {
		printf("\n");
		mc_print(mc);
		printf("%s", prompt);

		if (scanf(" %c", &input) != 1) {
			fprintf(stderr, "Error while reading input.\n");
			exit(1);
		}

		switch (input) {
		case 'a':
		case 'A':
			mc_add_1000(mc);
			break;
		case 's':
		case 'S':
			mc_add_100(mc);
			break;
		case 'd':
		case 'D':
			mc_add_10(mc);
			break;
		case 'f':
		case 'F':
			mc_add_1(mc);
			break;
		case 'r':
		case 'R':
			mc_reset(mc);
			break;
		case 'x':
		case 'X':
			break;
		default:
			puts("Invalid choice. Please try again.");
			break;
		}
	}

	mc_free(&mc);
}
