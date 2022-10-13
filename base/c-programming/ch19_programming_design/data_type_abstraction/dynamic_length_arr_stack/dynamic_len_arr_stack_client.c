/*
 * @author Anger
 * @date 2022/10/12
 * @brief 测试抽象的数据类型 Stack
 * 创建两个 Stack 并执行各种操作
 */
#include <stdio.h>
#include "dynamic_len_arr_stack.h"

int main(void) {

    Stack s1, s2;
    int n, stack_size = 10;

    s1 = create(stack_size);
    s2 = create(stack_size);

    push(s1, 1);
    push(s1, 2);

    n = pop(s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    n = pop(s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    destroy(s1);

    while (!is_empty(s2))
        printf("Popped %d from s2\n", pop(s2));
    push(s2, 3);
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}