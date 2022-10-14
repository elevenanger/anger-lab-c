/*
 * @author Anger
 * @date 2022/10/14
 * @brief 逆波兰表示法
 */
#include "rpn.h"
#include <stdio.h>

void rpn_cal(void) {
    bool is_quit = false;
    printf("Enter a RPN expression : ");
    do {
        char ch;
        scanf(" %c", &ch);
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
            case '=' : print_result(); break;
            default:
                printf("Quit\n");
                is_quit = true;
                break;
        }
    } while (!is_quit);
}

void print_result(void) {
    printf("Value of expression : %d\n", pop());
    make_empty();
    printf("Enter a RPN expression : ");
}