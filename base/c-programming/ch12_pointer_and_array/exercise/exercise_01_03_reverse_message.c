/*
 * @author Anger
 * @date 2022/9/14
 * @brief 输入一条消息
 * 然后逆序打印出来
 */
#include <stdio.h>
#define ARR_NUM 100

void input_message(char *p, int *n);

void reverse_print(char *p, int n);

int main(void) {
    char a[ARR_NUM];
    int n = 0;
    /* exercise_03 数组名作为指针 */
    input_message(a, &n);
    printf("n => %d\n", n);
    reverse_print(a, n);
    return 0;
}

void input_message(char *p, int *n) {
    printf("Enter a message :");
    while ((*p++ = getchar()) != '\n' && *n < ARR_NUM) (*n)++;
}

void reverse_print(char *p, int n) {
    char *q = p;
    p = p + n - 1;
    while (p >= q)
        printf("%c", *p--);
}