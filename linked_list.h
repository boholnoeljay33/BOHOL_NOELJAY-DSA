//
// Created by Admin on 10/6/2025.
//

#ifndef BOHOL__LINKED_LIST_H
#define BOHOL__LINKED_LIST_H

#include <stddef.h>

// Linked list node
typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

// Linked list container
typedef struct {
    LinkedListNode *head;
    size_t size;
} LinkedList;

// Function declarations
void linked_list_init(LinkedList *list);
void linked_list_destroy(LinkedList *list);
void linked_list_append(LinkedList *list, void *data);
void linked_list_insert(LinkedList *list, size_t index, void *data);
void linked_list_remove(LinkedList *list, size_t index);
void *linked_list_get(LinkedList *list, size_t index);
void linked_list_clear(LinkedList *list);

#endif // BOHOL__LINKED_LIST_H
