/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 格式化用户输入的产品信息
 */
#include <stdio.h>

int main() {
    int item_number, year, month, day;
    float price;

    puts("Enter item number : ");
    scanf("%d", &item_number);

    puts("Enter unit price : ");
    scanf("%f", &price);

    puts("Enter purchase date (mm/dd/yyyy)");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item      \tUnit      \tPurchase  \n"
           "          \tPrice     \tDate      \n"
           "%-10d\t$%9.2f\t%2d/%2d/%4d",
           item_number, price, month, day, year);

    return 0;
}