/*
 * @author Anger
 * @date 2022/10/27
 * @brief 调用 rand 函数 1000 次,观察低位的结果
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    for (i = 0; i < 1000; ++i)
        printf("%d ", rand() & 1);
    printf("\n");
    return 0;
}