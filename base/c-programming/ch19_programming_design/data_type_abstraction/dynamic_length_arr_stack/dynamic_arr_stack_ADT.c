/*
 * @author Anger
 * @date 2022/10/13
 * @brief 动态数组实现栈结构
 */
#include <stdlib.h>
#include <stdio.h>
#include "dynamic_len_arr_stack.h"

struct stack_type {
    Item *contents;
    int top;
    /* 新增一个 size 字段来存储栈的最大容量 */
    int size;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(int size) {
    Stack stack = malloc(sizeof(struct stack_type));
    if (stack == NULL)
        terminate("Error in create, stack couldn't be created.");

    stack->contents = malloc(size * sizeof(Item));
    if (stack->contents == NULL)
        terminate("Error in create, stack couldn't be created.");

    stack->top = 0;
    stack->size = size;
    return stack;
}

void destroy(Stack stack) {
    free(stack->contents);
    free(stack);
}

void make_empty(Stack stack) {
    stack->top = 0;
}

bool is_empty(Stack stack) {
    return stack->top == 0;
}

bool is_full(Stack stack) {
    return stack->top == stack->size;
}

void push(Stack stack, Item item) {
    if (is_full(stack))
        terminate("Error in push, stack is full.");
    stack->contents[stack->top++] = item;
}

Item pop(Stack stack) {
    if (is_empty(stack))
        terminate("Error in pop, stack is empty.");
    return stack->contents[--stack->top];
}