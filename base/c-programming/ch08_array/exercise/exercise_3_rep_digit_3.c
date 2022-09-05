/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 8.1 的程序
 * 可以输入多个数字进行重复数字的判断
 * 直到录入的数字小于等于 0 时，程序终止
 */
#include <stdio.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

int main(void) {

    int digit_seen[10] = {};

    int digit;
    long n;

    printf("Enter a number : ");
    scanf("%ld", &n);

    loop:
    for (int i = 0; i < SIZE(digit_seen); ++i)
        digit_seen[i] = 0;

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


    printf("\nEnter a number : ");
    scanf("%ld", &n);

    while (n > 0) goto loop;

    return 0;

}
