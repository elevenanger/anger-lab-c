/*
 * @author Anger
 * @date 2022/9/28
 * @brief 受限指针
 */
#include <stdlib.h>
#include <stdio.h>

void declare_restrict_pointer(void);

int main(void) {
    declare_restrict_pointer();
    return 0;
}

/**
 * 用 restrict 声明的指针是受限指针
 * 如果指针指向的对象后续需要修改
 * 那么该对象不允许通过指针 p 之外的任何方式访问
 */
void declare_restrict_pointer(void) {
    int * restrict p;
    int * restrict q;
    int *r;
    p = malloc(sizeof(int));
    q = p;
    *q = 10;
    printf("p => %d q => %d\n", *p, *q);
    r = q;
    printf("r => %d\n", *r);
}
