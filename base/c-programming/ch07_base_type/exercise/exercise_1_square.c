/*
 * @author Anger
 * @date 2022/9/2
 * @brief 找出每种整型最大可以求平方的数值
 */
#include <stdio.h>

int main(void) {

    long l = 2;

    short count = 0;

    /*
     * 如果求值是正数
     * 一旦达到最大的 signed short 上限
     * 数值类型会自动提升为 unsigned short
     */
    while ((short) (l * l)) {
        printf("%ld\n", l += 2);
        count++;
        if (count % 24 == 0) {
            printf("\nPlease press enter to continue : ");
            while (getchar() == '\n')
                continue;
        }
    }

    printf("\nShort upper limit : %ld\n", l);

    while ((int) (l * l))
        printf("%ld\n", l *= l);

    printf("Int upper limit : %ld\n", l);

    while (l * l)
        printf("%ld\n", l *= l);

    printf("long upper limit : %ld\n", l);

    /*
     * To short : 256
     * Int upper limit : 65536
     * Int upper limit : 4294967296
     */
}