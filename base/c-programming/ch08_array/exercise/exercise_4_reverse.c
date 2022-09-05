/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 reverse 程序
 * 使用 (int) (sizeof(a) / sizeof(a[0])） 来计算数组的长度
 */
#include <stdio.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))
#define ARR_NUMBER 5

int main(void) {

    int a[ARR_NUMBER];

    printf("Enter %d number : ", ARR_NUMBER);

    for (int i = 0; i < SIZE(a); i++)
        scanf("%d", &a[i]);

    for (int i = SIZE(a) - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;

}