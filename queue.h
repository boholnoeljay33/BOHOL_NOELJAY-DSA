#ifndef BOHOL__QUEUE_H
#define BOHOL__QUEUE_H

#include <stddef.h>  // For size_t

// Node in the queue
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Queue structure
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function declarations
void queue_init(Queue *queue);
void queue_deinit(Queue *queue);
void queue_enqueue(Queue *queue, int data);
int queue_dequeue(Queue *queue);
int queue_peek_head(Queue *queue);
int queue_peek_tail(Queue *queue);

#endif // BOHOL__QUEUE_H
