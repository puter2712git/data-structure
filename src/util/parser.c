#include "parser.h"

#include <stdio.h>
#include <string.h>

int parse_command(char* command, char* out[], int* out_arg_cnt)
{
    int index = 0;
    char* curr = strtok(command, " ");
    while (curr != NULL) {
        out[index] = curr;
        index += 1;
        curr = strtok(NULL, " ");
    }
    *out_arg_cnt = index;
}