/*
 * @author Anger
 * @date 2022/10/13
 * @brief 括号栈实现
 */
#include "brackets_stack.h"

Brackets brackets = {.top = 0};

void make_empty(void) {
    brackets.top = 0;
}

bool is_empty(void) {
    return brackets.top == 0;
}

bool is_full(void) {
    return brackets.top == BRACKETS_SIZE;
}

void push(Bracket bracket) {
    if (!is_bracket(bracket))
        return;

    if (is_full())
        exit(EXIT_FAILURE);

    brackets.bracket_contents[brackets.top++] = bracket;
}

Bracket pop(void) {
    if (is_empty())
        exit(EXIT_FAILURE);

    return brackets.bracket_contents[--brackets.top];
}

bool is_bracket(Bracket bracket) {
    switch (bracket) {
        case '{': case '}': case '(': case ')':
            return true;
        default: return false;
    }
}