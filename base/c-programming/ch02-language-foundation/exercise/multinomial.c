/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 计算多项式
 */
#include <stdio.h>

float multinomial(float x) {
    return 3 * x * x * x * x * x +
            2 * x * x * x * x -
            5 * x * x * x -
            1 * x * x +
            7 * x -
            6;
}

/**
 * 使用霍纳法则对多项式进行求值
 * 霍纳法则对每一次求值的结果进行充分的利用
 * 减少乘法的次数
 * @param x 参数
 * @return 多项式求值的结果
 */
float multinomial_honer_rule(float x) {
    return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}

int main(void) {

    float x;

    puts("Enter a number : ");

    scanf("%f", &x);

    printf("Multinomial evaluation result : %.2f\n", multinomial(x));
    printf("Multinomial evaluation result : %.2f\n", multinomial_honer_rule(x));

    return 0;
}