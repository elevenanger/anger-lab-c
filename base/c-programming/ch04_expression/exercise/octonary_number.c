/*
 * 输入一个数字
 * 按照八进制进行展示
 */
#include <stdio.h>

int main(void) {

    int i;
    puts("Enter a number between 0 and 32767 : ");
    scanf("%d", &i);

    int o1, o2, o3, o4, o5;
    o1 = i % 8;
    i /= 8;
    o2 = i % 8;
    i /= 8;
    o3 = i % 8;
    i /= 8;
    o4 = i % 8;
    i /= 8;
    o5 = i % 8;

    printf("Octal number : %d%d%d%d%d", o5, o4, o3, o2, o1);

    return 0;
}