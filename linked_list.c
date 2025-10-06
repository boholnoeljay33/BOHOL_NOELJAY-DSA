#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Initialize the linked list
void linked_list_init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

// Free all memory used by the list
void linked_list_destroy(LinkedList *list) {
    linked_list_clear(list);
}

// Append a node to the end
void linked_list_append(LinkedList *list, void *data) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        LinkedListNode *last = list->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }

    list->size += 1;
}

// Insert a node at a specific index
void linked_list_insert(LinkedList *list, size_t index, void *data) {
    if (index > list->size) return;

    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    node->data = data;

    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        LinkedListNode *prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }

    list->size += 1;
}

// Remove a node at a specific index
void linked_list_remove(LinkedList *list, size_t index) {
    if (index >= list->size || list->head == NULL) return;

    LinkedListNode *temp;
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        LinkedListNode *prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }

    free(temp);
    list->size -= 1;
}

// Get a node's data by index
void *linked_list_get(LinkedList *list, size_t index) {
    if (index >= list->size) return NULL;

    LinkedListNode *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

// Clear all nodes from the list
void linked_list_clear(LinkedList *list) {
    LinkedListNode *current = list->head;
    while (current != NULL) {
        LinkedListNode *temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->size = 0;
}
