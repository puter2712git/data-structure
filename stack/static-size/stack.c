#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"
#include "types.h"

element stack[MAX_STACK_SIZE];
int top = -1;

void initialize()
{
	memset(stack, 0, sizeof(stack));
	top = -1;
}

void finalize() {
	for (int i = 0; i <= top; i++) {
		free(stack[i]);
	}
}

bool is_empty()
{
	return top == -1;
}

bool is_full()
{
	return top == MAX_STACK_SIZE;
}

void push(element item)
{
	if (is_full()) return;

	stack[++top] = malloc(sizeof(char) * strlen(item + 1));
	strcpy(stack[top], item);
}

element pop()
{
	if (is_empty()) {
		printf("Stack is empty.\n");
		return "";
	}

	printf("%s popped.\n", stack[top]);
	free(stack[top]);
	return stack[top--];
}

void dump()
{
	for (int i = 0; i <= top; i++) {
		printf("- [%2d]: %s\n", i, stack[i]);
	}
}