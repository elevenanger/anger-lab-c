/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 贷款计算器
 */
#include <stdio.h>


float rate, amount, monthly_payment;

float pay() {
    amount = (amount - monthly_payment) + (amount * rate / 100 / 12);
    return amount;
}

int main() {

    puts("Enter amount of loan : ");
    scanf("%f", &amount);
    puts("Enter rate : ");
    scanf("%f", &rate);
    puts("Enter monthly payment : ");
    scanf("%f", &monthly_payment);

    printf("Balance remaining after 1st month : %.2f\n", pay());
    printf("Balance remaining after 2nd month : %.2f\n", pay());
    printf("Balance remaining after 3rd month : %.2f\n", pay());

    return 0;
}