/*
 * @author Anger
 * @date 2022/9/3
 * @brief 使用牛顿法求算数平方根
 * x  是用户输入的数字
 * 牛顿法先给出 x 的平方根的猜想值 y （程序中都使用 1）
 * 后续的猜测过程通过计算 y 与 x / y 的平均值求得
 * y 的值逐渐接近 x 的平方根
 * 为了获得更高的精度
 */
#include <stdio.h>
#include <math.h>

int main(void) {

    int x;
    double y = 1, new_y;

    double precision = 0.00001;

    printf("Enter a positive number: ");
    scanf("%d", &x);

    do {
        new_y = (y + (x / y)) / 2;

        if (fabs(y - new_y) < precision)
            break;

        y = new_y;
    } while (1);

    printf("Square root : %f", y);

    return 0;
}