/*
 * @author Anger
 * @date 2022/10/14
 * @brief 逆波兰表示法
 */
#include <stdbool.h>

#ifndef ANGER_LAB_C_RPN_H
#define ANGER_LAB_C_RPN_H
#define MAX_ITEM 20

typedef int rpn_item;

struct rpn_stack {
    int top;
    rpn_item rpn_items[MAX_ITEM];
};

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(rpn_item item);
rpn_item pop(void);
void rpn_cal(void);
void print_result(void);

#endif //ANGER_LAB_C_RPN_H
