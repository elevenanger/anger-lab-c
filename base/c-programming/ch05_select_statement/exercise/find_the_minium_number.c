/*
 * 从 4 个整数中找出最小值
 */
#include <stdio.h>

void switch_number (int *a, int *b) {
    int i;
    i = *a;
    *a = *b;
    *b = i;
}

int main(void) {

    int n1, n2, n3, n4;

    puts("Enter four integers : ");

    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if (n1 > n2) switch_number(&n1, &n2);
    if (n3 > n4) switch_number(&n3, &n4);
    if (n1 > n3) switch_number(&n1, &n3);
    if (n2 > n4) switch_number(&n2, &n4);

    printf("max number : %d\n"
           "min number : %d\n",
           n4, n1);

    return 0;
}