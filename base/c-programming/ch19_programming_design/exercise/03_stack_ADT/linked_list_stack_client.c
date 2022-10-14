/*
 * @author Anger
 * @date 2022/10/12
 * @brief 测试抽象的数据类型 Stack
 * 创建两个 Stack 并执行各种操作
 */
#include <stdio.h>
#include "linked_list_stack.h"

void print_length(char *stack_name, Stack stack) {
    printf("stack %s length => %d\n", stack_name, length(stack));
}

int main(void) {

    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    print_length("s1", s1);
    push(s1, 2);
    print_length("s1", s1);

    n = pop(s1);
    print_length("s1", s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    print_length("s2", s2);
    n = pop(s1);
    print_length("s1", s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    print_length("s2", s2);
    destroy(s1);

    while (!is_empty(s2)) {
        printf("Popped %d from s2\n", pop(s2));
        print_length("s2", s2);
    }

    push(s2, 3);
    printf("Popped %d from s2\n", pop(s2));
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}