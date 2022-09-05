/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 8.1 的程序，是的打印一份列表
 * 展示每个数字出现的次数
 */
#include <stdio.h>

int main(void) {

    int digit_seen[10] = {};

    int digit;
    long n;

    printf("Enter a number : ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit] += 1;
        n /= 10;
    }

    printf("digit :       ");
    for (int i = 0; i < 10; ++i)
        printf("%d ", i);


    printf("\noccurrences : ");
    for (int i = 0; i < 10; ++i)
        printf("%d ", digit_seen[i]);

    return 0;

}