/*
 * @author Anger
 * @date 2022/9/10
 * @brief 输入一连串的括号和花括号
 * 检查括号的嵌套关系是否匹配
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

int top = 0;
char contents[STACK_SIZE];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
char pop(void);


int main(void) {
    printf("Enter parentheses and/or braces : ");
    char ch;
    bool is_match = true;
    while (is_match && (ch = getchar()) != '\n') {
        switch (ch) {
            case '{':
            case '(':
                push(ch);
                break;
            case '}':
                if (is_empty() || pop() != '{') is_match = false;
                break;
            case ')':
                if (is_empty() || pop() != '(') is_match = false;
                break;
            default:
                break;
        }
    }

    if (!is_empty()) is_match = false;

    if (is_match) printf("Parentheses / braces are nested properly.");
    else printf("Parentheses / braces are not nested properly.");

    make_empty();

    return 0;
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

void push(char ch) {
    if (is_full()) {
        printf("stack full!");
        exit(EXIT_SUCCESS);
    }
    contents[top++] = ch;
}

char pop() {
    if (is_empty()) {
        printf("Stack is empty");
        exit(EXIT_SUCCESS);
    }
    return contents[--top];;
}