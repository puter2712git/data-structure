#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

typedef char* element;

typedef struct node {
	element data;
	struct node *next;
} Node;

typedef struct queue {
	struct node *front;
	struct node *rear;
} Queue;


void initialize();
void finalize();

bool is_empty();

void push(element item);
element pop();

void dump();

#endif