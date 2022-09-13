/*
 * @author Anger
 * @date 2022/9/12
 * @brief 输入一个金额，计算最少需要多少张纸币
 * 纸币的面额 20 10 5 1
 */
#include <stdio.h>
/*
 * 纸币的面额
 */
#define DENOMINATION_TWENTY 20;
#define DENOMINATION_TEN  10;
#define DENOMINATION_FIVE  5;

void pay_amount
        (int amount, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
    int amount;
    puts("Enter amount : ");

    scanf("%d", &amount);

    int count_of_twenty = 0;
    int count_of_ten = 0;
    int count_of_five = 0;
    int count_of_one = 0;

    pay_amount(amount, &count_of_twenty, &count_of_ten, &count_of_five, &count_of_one);

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

void pay_amount
        (int amount, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = amount / DENOMINATION_TWENTY;
    amount = amount % DENOMINATION_TWENTY;

    *tens = amount / DENOMINATION_TEN;
    amount = amount % DENOMINATION_TEN;

    *fives = amount / DENOMINATION_FIVE;
    amount = amount % DENOMINATION_FIVE;

    *ones = amount;
}
