/*
 * @author Anger
 * @date 2022/10/13
 * @brief 判断括号匹配
 */
#include <stdlib.h>
#include <stdbool.h>

#ifndef ANGER_LAB_C_BRACKETS_STACK_H
#define ANGER_LAB_C_BRACKETS_STACK_H
#define BRACKETS_SIZE 10

typedef char Bracket;

typedef struct brackets_stack {
    int top;
    Bracket bracket_contents[BRACKETS_SIZE];
} Brackets;


void make_empty(void);
bool is_full(void);
bool is_empty(void);
void push(Bracket bracket);
Bracket pop(void);

bool is_bracket(Bracket bracket);

#endif //ANGER_LAB_C_BRACKETS_STACK_H
