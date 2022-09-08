/*
 * @author Anger
 * @date 2022/9/8
 * @brief 用户输入应纳税税的金额
 * 返回税金
 */
#include <stdio.h>

double cal_tax(double income) {
    double tax;
    if (income < 750.0f)
        tax = income*0.01;
    else if (income < 2250.0f)
        tax = 7.5 + (income - 750)*0.02;
    else if (income < 3750.0f)
        tax = 37.5 + (income-2250)*0.03;
    else if (income < 5250.0f)
        tax = 82.5 + (income-3650)*0.04;
    else if (income < 7000.0f)
        tax = 142.5 + (income-5250)*0.05;
    else
        tax = 230 + (income-7000)*0.06;
    return tax;
}

int main(void){
    float income;

    printf("Enter the taxable income : ");
    scanf("%f", &income);

    printf("The Tax is %.2f", cal_tax(income));
    return 0;
}
