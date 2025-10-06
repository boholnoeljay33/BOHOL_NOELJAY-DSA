//
// Created by Admin on 10/6/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Initialize the queue
void queue_init(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Deinitialize the queue and free all nodes
void queue_deinit(Queue *queue) {
    QueueNode *current = queue->front;
    while (current != NULL) {
        QueueNode *temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = NULL;
    queue->rear = NULL;
}

// Enqueue an element to the rear of the queue
void queue_enqueue(Queue *queue, int data) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        // Queue is empty
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Dequeue an element from the front of the queue
int queue_dequeue(Queue *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }

    QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Peek at the front element
int queue_peek_head(Queue *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Peek at the rear element
int queue_peek_tail(Queue *queue) {
    if (queue->rear == NULL) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    return queue->rear->data;
}
