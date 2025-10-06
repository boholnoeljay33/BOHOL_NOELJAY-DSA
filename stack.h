#ifndef BOHOL__STACK_H
#define BOHOL__STACK_H

#include <stddef.h>

// Node in the stack
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

// Stack structure
typedef struct {
    StackNode *top;
    size_t size;
} Stack;

// Function declarations
void stack_init(Stack *stack);
void stack_definit(Stack *stack);
void stack_push(Stack *stack, int data);
int stack_pop(Stack *stack);
int stack_peek(Stack *stack);

#endif // BOHOL__STACK_H
