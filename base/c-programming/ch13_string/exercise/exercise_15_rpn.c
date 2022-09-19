/*
 * @author Anger
 * @date 2022/9/19
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 20

int top;
int stack[STACK_SIZE];

int evaluate_rpn_expression(const char *expression);
bool is_empty(void);
bool is_full(void);
void push(int operand);
int pop(void);
void make_empty(void);
void print_result(void);

int main(void) {
    char expression[40], c, *p = expression;
    while ((c = getchar()) != '\n') {
        *p++ = c;
    }
    *p = '\0';
    printf("RPN evaluation result => %d\n", evaluate_rpn_expression(expression));
    return 0;
}

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

void print_result(void) {
    printf("Value of expression : %d\n", pop());
    make_empty();
    printf("Enter a RPN expression : ");
}

int evaluate_rpn_expression(const char *expression) {
    int result = 0;
    bool is_quit = false;
    do {
        char ch = *expression;
        switch (ch) {
            /* 数字则压入栈 */
            case '1':  push(1); break;
            case '2':  push(2); break;
            case '3':  push(3); break;
            case '4':  push(4); break;
            case '5':  push(5); break;
            case '6':  push(6); break;
            case '7':  push(7); break;
            case '8':  push(8); break;
            case '9':  push(9); break;
                /* 运算符则 取出两个操作数进行处理 */
            case '+' : push(pop() + pop()); break;
            case '-' : push(-pop() + pop()); break;
            case '*' : push(pop() * pop()); break;
            case '/' : push(1.0f / pop() * pop()); break;
            case ' ' : break;
            case '=' : result = pop(); break;
            default:
                printf("Quit\n");
                is_quit = true;
                break;
        }
        expression++;
    } while (!is_quit);
    return result;
}