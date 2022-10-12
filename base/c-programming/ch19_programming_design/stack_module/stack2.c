/*
 * @author Anger
 * @date 2022/10/12
 * @brief 使用链表实现栈结构
 * 这充分体现了模块的好处
 * stack1 和 stack2 分别使用了不同的数据结构来说实现 stack
 * 但是在外部看来是一样的，隐藏了具体的实现细节
 * 使得程序更易于维护
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    while (!is_empty())
        pop();
}

bool is_empty(void) {
    return top == NULL;
}

bool is_full(void) {
    return false;
}

int pop(void) {
    struct node *old_top;
    int i;

    if (is_empty())
        terminate("Error in pop, stack is empty!\n");

    old_top = top;
    top = top->next;
    i = old_top->data;
    free(old_top);
    return i;
}

void push(int i) {
    struct node *new_top = malloc(sizeof(struct node));

    if (new_top == NULL)
        terminate("Error in push, memory is full!\n");

    new_top->data = i;
    new_top->next = top;
    top = new_top;
}