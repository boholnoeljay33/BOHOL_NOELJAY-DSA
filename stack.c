//
// Created by Admin on 10/6/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initialize the stack
void stack_init(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Free all elements in the stack
void stack_definit(Stack *stack) {
    StackNode *current = stack->top;
    while (current != NULL) {
        StackNode *temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->size = 0;
}

// Push an element onto the stack
void stack_push(Stack *stack, int data) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int stack_pop(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // sentinel value
    }

    StackNode *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Peek at the top element without removing it
int stack_peek(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // sentinel value
    }
    return stack->top->data;
}
