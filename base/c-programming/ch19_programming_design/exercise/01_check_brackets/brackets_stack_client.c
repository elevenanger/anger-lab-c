/*
 * @author Anger
 * @date 2022/10/13
 * @brief  
 */
#include <stdio.h>
#include "brackets_stack.h"

int main(void) {
    Bracket bracket;

    printf("Enter brackets ( { } ( ) ): \n");

    do {
        bracket = getchar();
        if (bracket == '(' || bracket == '{')
            push(bracket);
        else if (bracket == ')') {
            if (pop() != '(')
                return 1;
        } else if (bracket == '}') {
            if (pop() != '{')
                return 1;
        }
    } while (bracket != '\n');

    printf("Brackets are matched.\n");

    return 0;
}