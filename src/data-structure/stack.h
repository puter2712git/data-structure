#ifndef __STACK_H__
#define __STACK_H__

#define STACK_DEFAULT_SIZE 100

typedef struct stack {
    int top;
    int capacity;
    char** data;
} stack;

extern stack* stk;

int stack_initialize();
int stack_finalize();

int stack_push(char* str);
char* stack_pop();

int stack_dump();

int stack_is_empty();
int stack_is_full();

#endif