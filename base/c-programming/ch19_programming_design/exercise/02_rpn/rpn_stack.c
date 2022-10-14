/*
 * @author Anger
 * @date 2022/10/14
 * @brief rpn stack 数据结构方法实现
 */
#include "rpn.h"

struct rpn_stack stack = {.top = 0};

void make_empty(void) {
    stack.top = 0;
}

bool is_empty(void) {
    return stack.top == 0;
}

bool is_full(void) {
    return stack.top == MAX_ITEM;
}

void push(rpn_item item) {
    stack.rpn_items[stack.top++] = item;
}

rpn_item pop(void) {
    return stack.rpn_items[--stack.top];
}