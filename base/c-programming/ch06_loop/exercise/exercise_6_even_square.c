/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入一个数 n 显示 1 - n 中所有的偶数平方值
 */
#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a number : ");

    scanf("%d", &n);
    if (n <= 1) return 1;

    int i = 0;

    while ((i+=2) <= n)
        printf("%d\n", i * i);

}