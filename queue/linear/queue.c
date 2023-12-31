#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue *queue;

void initialize()
{
	queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
}

void finalize()
{
	free(queue);
}

bool is_empty()
{
	return !queue->front && !queue->rear;
}

void push(element item)
{
	Node *new = (Node*)malloc(sizeof(Node));
	new->data = (element)malloc(sizeof(char) * (strlen(item) + 1));
	strcpy(new->data, item);
	new->next = NULL;

	if (is_empty()) {
		queue->front = new;
	} else {
		queue->rear->next = new;
	}
	queue->rear = new;
}

element pop()
{
	Node *del = queue->front;
	element popped = del->data;
	queue->front = del->next;

	free(del);

	return popped;
}

void dump()
{
	Node *curr = queue->front;
	int index = 0;

	while (curr) {
		printf("- [%2d]: %s\n", index, curr->data);

		curr = curr->next;
		index++;
	}
}