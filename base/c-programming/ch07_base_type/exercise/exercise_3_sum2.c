/*
 * @author Anger
 * @date 2022/9/2
 * @brief 修改程序可以进行浮点值运算
 */
#include <stdio.h>

int main(void) {
    double n, sum = 0;

    printf("This program sums a series of floats.\n");
    printf("Enter integers (0 to terminate): ");
    scanf("%lf", &n);
    while (n != 0.0) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %f\n", sum);
    return 0;
}