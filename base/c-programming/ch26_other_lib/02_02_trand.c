/*
 * @author Anger
 * @date 2022/10/27
 * @brief 伪随机数
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i, seed;

    printf("前五个随机数.\n");

    for (;;) {
        for (i = 0; i < 5; ++i)
            printf("%d ", rand());

        printf("\n\n");
        printf("输入 seed 值: ");

        scanf("%d", &seed);

        if (seed == 0)
            break;
        srand(seed);
    }

    return 0;
}