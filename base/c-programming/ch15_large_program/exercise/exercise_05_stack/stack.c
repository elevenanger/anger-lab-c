/*
 * @author Anger
 * @date 2022/9/22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 20

int top;
int stack[STACK_SIZE];

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int operand) {
    if (is_full()) {
        printf("Expression is too complex!");
        exit(EXIT_FAILURE);
    }
    stack[top++] = operand;
}

int pop(void) {
    if (is_empty()) {
        printf("Not enough operands in expression.");
        exit(EXIT_FAILURE);
    }
    return stack[--top];
}

void make_empty(void) {
    top = 0;
}
