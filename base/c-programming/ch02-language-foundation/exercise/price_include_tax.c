/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 计算含税价格
 */
#include <stdio.h>
#define TAX_RATE 0.05

int main(void) {
    float price;
    puts("Enter price : ");
    scanf("%f", &price);

    printf("Price including tax : %.2f\n",
           price * (1 + TAX_RATE));

    return 0;
}