/*
 * @author Anger
 * @date 2022/9/1
 * @brief 输入一个分数
 * 输出最简分式
 */
#include <stdio.h>
#include "greatest_divisor.h"

int main(void) {

    int numerator, denominator, max_divisor;

    printf("Enter a fraction : ");
    scanf("%d/%d", &numerator, &denominator);

    if (denominator == 0) return -1;

    max_divisor = largest_divisor(numerator, denominator);

    printf("In lowest form : %d/%d",
           numerator / max_divisor, denominator / max_divisor);

    return 0;
}