/*
 * 将数字转换为等级
 * 90-100 A
 * 80-89 B
 * 70-79 C
 * 60-69 D
 * 0-59 F
 */
#include <stdio.h>

int main(void) {

    int ten_digit, score;

    puts("Enter score : ");
    scanf("%d", &score);

    ten_digit = score / 10;

    if (score < 0 || score > 100)
        return 1;

    printf("Letter grade : ");

    switch (ten_digit) {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("F");
    }
    
    return 0;
}