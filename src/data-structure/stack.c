#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

stack* stk = NULL;

int stack_initialize()
{
    stk = (stack*)malloc(sizeof(stack));
    stk->top = -1;
    stk->capacity = STACK_DEFAULT_SIZE;
    stk->data = (char**)malloc(sizeof(char*) * stk->capacity);

    return 0;
}

int stack_finalize()
{
    for (int i = 0; i < stk->capacity; i++) {
        free(stk->data[i]);
    }
    free(stk->data);
    free(stk);

    return 0;
}

int stack_push(char* str)
{
    if (stack_is_full()) {
        stk->capacity += STACK_DEFAULT_SIZE;
        stk->data = (char**)realloc(stk->data, sizeof(char*) * stk->capacity);
    }

    stk->top += 1;
    
    char* copy_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(copy_str, str);
    stk->data[stk->top] = copy_str;

    return 0;
}

char* stack_pop()
{
    if (stack_is_empty()) {
        return NULL;
    }

    int pop_index = stk->top;
    stk->top -= 1;

    return stk->data[pop_index];
}

int stack_dump()
{
    if (stack_is_empty()) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i <= stk->top; i++) {
        fprintf(stdout, "[%2d]: %s\n", i, stk->data[i]);
    }

    return EXIT_SUCCESS;
}

int stack_is_empty()
{
    return stk->top == -1;
}

int stack_is_full()
{
    return stk->top == (stk->capacity - 1);
}