/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 给定一个金额
 * 分别计算最少需要多少张 20 10 5 1 面额的纸币
 */
#include <stdio.h>
/*
 * 纸币的面额
 */
#define DENOMINATION_TWENTY 20;
#define DENOMINATION_TEN  10;
#define DENOMINATION_FIVE  5;

int main(void) {
    int amount;

    int count_of_twenty = 0;
    int count_of_ten = 0;
    int count_of_five = 0;
    int count_of_one = 0;

    puts("Enter amount : ");

    scanf("%d", &amount);

    count_of_twenty = amount / DENOMINATION_TWENTY;
    amount = amount % DENOMINATION_TWENTY;

    count_of_ten = amount / DENOMINATION_TEN;
    amount = amount % DENOMINATION_TEN;

    count_of_five = amount / DENOMINATION_FIVE;
    amount = amount % DENOMINATION_FIVE;

    count_of_one = amount;

    printf("20 bills : %d\n"
           "10 bills : %d\n"
           "5  bills : %d\n"
           "1  bills : %d\n",
           count_of_twenty,
           count_of_ten,
           count_of_five,
           count_of_one);

    return 0;
}