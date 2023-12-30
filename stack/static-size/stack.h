#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STACK_SIZE 100

#include <stdbool.h>

#include "types.h"

void initialize();
void finalize();

bool is_empty();
bool is_full();

void push(element item);
element pop();

void dump();

#endif