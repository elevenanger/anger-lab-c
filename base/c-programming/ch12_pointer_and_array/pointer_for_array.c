/*
 * @author Anger
 * @date 2022/9/13
 * @brief 指针用于数组处理
 */
#include <stdio.h>

void sum(void);

void pointer_auto_increment_expression(void);

void reverse(void);

int main(void) {
    sum();
    pointer_auto_increment_expression();
    reverse();
    return 0;
}

void sum(void) {
    /* 指针指向数组符合字面量 */
    int *p = (int []) {1, 2, 3, 4, 5}, sum = 0;
    for (int i = 0; i < 5; ++i)
        /* 对指针进行自增，间接寻址运算符取出指针指向的值
         * 使用该值进行求和
         * ++ 运算符的优先级要高于 *
         * 所以 *p++ 等价于 *(p++) */
        sum += *p++;
    printf("sum => %d\n", sum);
}

/**
 * 间接寻址符 * 与自增表达式 ++ 的组合
 * 自减表达式的用法和自增表达式相同
 */
void pointer_auto_increment_expression(void) {
    int *p = (int []) {1, 3, 5, 7, 9, 11};
    /* *p++ 等价于 *(p++)
     * 因为使用后缀 ++
     * p++ 的值是 p 只有在表达式计算出来才可以执行自增
     * 所以 *p++ 的值是 *p，即 p 当前指向的对象
     * 然后使用间接寻址符取 p 指向的对象的值 */
    printf("*p++ => %d\n", *p++);
    printf("*p => %d\n", *p);
    printf("*(p++) => %d\n", *(p++));
    printf("*p => %d\n", *p);

    /* 先通过 *p 取对象
     * 执行对象的自增 */
    printf("(*p)++ => %d\n", (*p)++);
    printf("*p => %d\n", *p);

    /* ++p 的值是 p 的自增
     * *++p 等价于 *(++p)
     * 先进行指针的自增
     */
    printf("*++p => %d\n", *++p);
    printf("*p => %d\n", *p);
    printf("*(++p) => %d\n", *(++p));
    printf("*p => %d\n", *p);

    /* ++*p 先取出对象
     * 对对象进行自增的操作
     * */
    printf("++*p => %d\n", ++*p);
    printf("*p => %d\n", *p);
}

void reverse(void) {
    int a[3] ,*p;
    printf("Enter 3 number : ");
    for (p = a; p < a + 3; p++)
        scanf("%d", p);

    for (int i = 0; i < 3; ++i)
        printf("%d ", a[i]);
    printf("\n");

    for (p = a + 3 - 1;p >= a; p--)
        printf("%d ", *p);
    printf("\n");
}
