#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_DEFAULT_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int capacity;
    char** data;
} queue;

extern queue* que;

int queue_initialize();
int queue_finalize();

int queue_enqueue(char* str);
char* queue_dequeue();

int queue_dump();

int queue_is_empty();
int queue_is_full();

#endif