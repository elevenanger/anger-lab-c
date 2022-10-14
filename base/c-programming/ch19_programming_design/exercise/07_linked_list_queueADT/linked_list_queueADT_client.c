/*
 * @author Anger
 * @date 2022/10/13
 * @brief  
 */
#include <stdio.h>
#include "linked_list_queue.h"

int main(void) {

    Queue queue = create_queue();

    Item bracket;

    printf("Enter brackets ( { } ( ) ): \n");

    do {
        bracket = getchar();
        if (bracket == '(' || bracket == '{')
            push(queue, bracket);
        else if (bracket == ')') {
            if (pop(queue) != '(')
                return 1;
        } else if (bracket == '}') {
            if (pop(queue) != '{')
                return 1;
        }
    } while (bracket != '\n');

    if (is_empty(queue))
        printf("Brackets are matched.\n");

    destroy_queue(queue);

    return 0;
}