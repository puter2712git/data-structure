#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

#include <stdbool.h>

#include "types.h"

void parse_input(char *input, char *tokens[], int *nr_token);

void print_usage();

void run_simulator();

#endif