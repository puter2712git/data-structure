#include <stdio.h>
#include <string.h>

#include "simulator.h"
#include "stack.h"

#define USER_INPUT_LEN 100
#define MAX_TOKEN_LEN 16

void parse_input(char *input, char *tokens[], int *nr_token)
{
	*nr_token = 0;

	char *curr = strtok(input, " ");

	while (curr) {
		tokens[(*nr_token)++] = curr;
		curr = strtok(NULL, " ");
	}
}

void print_usage() {
	printf("How to use\n");
	printf("- push [string]\n");
	printf("- pop\n");
	printf("- dump\n");
	printf("- quit\n");
}

void run_simulator()
{
	initialize();

	char *tokens[MAX_TOKEN_LEN] = { NULL };
	unsigned int nr_token = 0;

	while (true) {
		char input[USER_INPUT_LEN];

		printf(">> ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';

		parse_input(input, tokens, &nr_token);

		if (!strcmp(tokens[0], "push") && nr_token == 2) {
			push(tokens[1]);
		}
		else if (!strcmp(tokens[0], "pop") && nr_token == 1) {
			pop();
		}
		else if (!strcmp(tokens[0], "dump") && nr_token == 1) {
			dump();
		}
		else if (!strcmp(tokens[0], "quit") && nr_token == 1) {
			break;
		}
		else {
			print_usage();
		}
	}

	finalize();
}