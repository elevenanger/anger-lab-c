/*
 * @author Anger
 * @date 2022/10/12
 * @brief 用数组的形式实现栈
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

/**
 * 将 contents 和 top 声明为 static
 * 信息隐藏，防止外部程序发现这些信息
 */
static int contents[STACK_SIZE];
static int top = 0;

/**
 * 使用 static 声明的函数只能在模块内使用
 * 对外隐藏该函数
 */
static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

int pop(void) {
    if (is_empty())
        terminate("Error in pop, stack is empty!\n");
    return contents[--top];
}

void push(int i) {
    if (is_full())
        terminate("Error in push, stack is full!\n");
    contents[top++] = i;
}