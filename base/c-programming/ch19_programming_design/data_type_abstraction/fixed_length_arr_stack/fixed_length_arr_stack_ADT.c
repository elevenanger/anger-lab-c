/*
 * @author Anger
 * @date 2022/10/12
 * @brief ADT 抽象数据类型
 * 使用定长数组实现栈
 */
#include <stdio.h>
#include <stdlib.h>
#include "fixed_length_arr_stack.h"

#define STACK_SIZE 100

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create stack.\n");
    s->top = 0;
    return s;
}

void destroy(Stack stack) {
    free(stack);
}

void make_empty(Stack stack) {
    stack->top = 0;
}

bool is_empty(Stack stack) {
    return stack->top == 0;
}

bool is_full(Stack stack) {
    return stack->top == STACK_SIZE;
}

void push(Stack stack, Item i) {
    if (is_full(stack))
        terminate("Error in push, stack is full.\n");
    stack->contents[stack->top++] = i;
}

Item pop(Stack stack) {
    if (is_empty(stack))
        terminate("Error in pop, stack is empty.\n");
    return stack->contents[--stack->top];
}