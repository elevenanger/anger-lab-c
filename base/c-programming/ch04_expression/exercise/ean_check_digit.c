/*
 * 计算 EAN 规范校验位
 * 2 4 6 8 10 12 位数字相加，计算一个结果 s1
 * 1 3 5 7 9 11 位数字相加，计算一个结果 s2
 * 把第一次加法的结果乘以 3 s1 * 3
 * 再和第二次加法的结果相加 s1 * 3 + s2
 * 减去 1
 * 取 10 的余数
 * 用 9 减去余数
 */
#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4, i5, i6, i7,
        i8 ,i9, i10, i11, i12, s1, s2;
    puts("Enter the first 12 digits of EAN : ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
          &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8,
          &i9, &i10, &i11, &i12);
    s2 = i1 + i3 + i5 + i7 + i9 + i11;
    s1 = i2 + i4 + i6 + i8 + i10 + i12;

    printf("Check digits : %d\n", 9 - (s1 * 3 + s2 -1) % 10);

    return 0;
}
