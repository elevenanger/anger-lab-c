/**
* 给定一个 4 位整数
 * 输出数字的位数
*/
#include <stdio.h>

int main(void) {
    int number, digits;

    puts("Enter a number : ");
    scanf("%d", &number);

    if (number >= 0 && number <= 9) {
        digits = 1;
    } else if (number >= 10 && number <= 99) {
        digits = 2;
    } else if (number >= 100 && number <= 999) {
        digits = 3;
    } else if (number >= 1000 && number <= 9999) {
        digits = 4;
    } else {
        digits = -1;
    }

    printf("The number is %d digits.\n", digits);

    return 0;
}