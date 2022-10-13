/*
 * @author Anger
 * @date 2022/10/13
 * @brief 链表实现栈
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list_stack.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack stack = malloc(sizeof(struct stack_type));
    if (stack == NULL)
        terminate("Error in create, stack couldn't be created.");

    stack->top = NULL;

    return stack;
}

void destroy(Stack stack) {
    make_empty(stack);
    free(stack);
}

void make_empty(Stack stack) {
    while (!is_empty(stack))
        pop(stack);
}

bool is_empty(Stack stack) {
    return stack->top == NULL;
}

bool is_full(Stack stack) {
    return false;
}

void push(Stack stack, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push, stack is full.");

    new_node->data = item;
    new_node->next = stack->top;
    stack->top = new_node;
}

Item pop(Stack stack) {
    if (is_empty(stack))
        terminate("Error in pop, stack is empty.");

    struct node *popped_node = stack->top;
    Item item = popped_node->data;
    stack->top = stack->top->next;
    free(popped_node);
    return item;
}