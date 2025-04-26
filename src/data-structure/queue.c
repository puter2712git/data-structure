#include "queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

queue* que = NULL;

int queue_initialize()
{
    que = (queue*)malloc(sizeof(queue));
    que->front = -1;
    que->rear = -1;
    que->capacity = QUEUE_DEFAULT_SIZE;
    que->data = (char**)malloc(sizeof(char*) * que->capacity);

    return 0;
}

int queue_finalize()
{
    for (int i = 0; i < que->capacity; i++) {
        free(que->data[i]);
    }
    free(que->data);
    free(que);

    return 0;
}

int queue_enqueue(char* str)
{
    if (queue_is_full()) {
        fprintf(stdout, "Queue is full! Resizing queue...\n");
        fprintf(stdout, "Capacity: %d -> %d\n", que->capacity, que->capacity + QUEUE_DEFAULT_SIZE);

        que->capacity += QUEUE_DEFAULT_SIZE;
        que->data = (char**)realloc(que->data, sizeof(char*) * que->capacity);
    }

    fprintf(stdout, "Enqueue new item to queue!\n");
    fprintf(stdout, "Item: %s\n", str);

    que->front += 1;

    char* copy_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(copy_str, str);
    que->data[que->front] = copy_str;

    return 0;
}

char* queue_dequeue()
{
    if (queue_is_empty()) {
        fprintf(stderr, "[!] Queue is empty! Cannot dequeue from queue.\n");
        return NULL;
    }

    int deq_index = que->rear + 1;
    que->rear += 1;

    return que->data[deq_index];
}

void queue_dump()
{
    if (queue_is_empty()) {
        fprintf(stderr, "[!] Queue is empty! Cannot dump queue.\n");
        return;
    }

    fprintf(stdout, "========== Dumping Queue ==========\n");
    for (int i = que->rear + 1; i <= que->front; i++) {
        fprintf(stdout, "[%2d]: %s\n", i, que->data[i]);
    }
}

int queue_is_empty()
{
    return que->front == que->rear;
}

int queue_is_full()
{
    return que->front == (que->capacity - 1);
}