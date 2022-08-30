/*
 * 输入一个二位数字
 * 然后将其按照逆序打印
 */
#include <stdio.h>

void reverse_two_digit_number() {
    int i;
    puts("Enter a two-digit number : ");
    scanf("%2d", &i);
    printf("The reversal is : %d\n", i % 10 * 10 + i / 10);
}

void reverse_three_digit_number() {
    int i;
    puts("Enter a three-digit number : ");
    scanf("%3d", &i);
    printf("The reversal is : %d\n",
           i % 100 % 10 * 100 +
           i / 10 % 10 * 10 +
           i / 100);
}

void reverse_three_digit_number_non_arithmetic() {
    int i, j, k;
    puts("Enter a three-digit number : ");
    scanf("%1d%1d%1d", &i, &j, &k);
    printf("The reversal is : %d%d%d\n",k, j, i);
}

int main(void) {

    reverse_two_digit_number();

    reverse_three_digit_number();

    reverse_three_digit_number_non_arithmetic();

    return 0;
}