#include <stdio.h>

#include "../inc/moocounter.h"

void print_MooCounter(MooCounter mc)
{
	printf("--------\n| ");
	if (mc->error(mc))
		printf("ERROR");
	else
		printf("%4d", mc->count(mc));
	printf(" |\n--------\n");
}

int main(void)
{
	const char *prompt =
		"[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it  ";
	char input = 0;

	MooCounter mc = mc_new();

	while (input != 'X' && input != 'x') {
		print_MooCounter(mc);
		printf("%s", prompt);
		scanf(" %c", &input);

		switch (input) {
		case 'a':
		case 'A':
			mc->add_1000(mc);
			break;
		case 's':
		case 'S':
			mc->add_100(mc);
			break;
		case 'd':
		case 'D':
			mc->add_10(mc);
			break;
		case 'f':
		case 'F':
			mc->add_1(mc);
			break;
		case 'r':
		case 'R':
			mc->reset(mc);
			break;
		case 'x':
		case 'X':
			break;
		default:
			puts("Invalid choice. Please try again.");
			break;
		}
	}
}
