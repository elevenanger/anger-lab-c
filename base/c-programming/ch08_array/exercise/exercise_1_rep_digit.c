/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改查找重复元素的代码
 * 可以查看到哪些元素有重复
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

    printf("repeat digits : ");
    for (int i = 0; i < 10; ++i)
        if (digit_seen[i] > 1)
            printf("%d ", i);

    return 0;
}