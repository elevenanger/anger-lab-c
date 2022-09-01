/*
 * @author Anger
 * @date 2022/9/1
 * @brief 用户一个个输入数字
 * 当输入 0 或者负数时
 * 显示当前输入的最大非负数
 */
#include <stdio.h>

int main(void) {
    int max = 0, input;

    for (; ;) {
        printf("Enter a number : ");
        scanf("%d", &input);

        if (input <= 0) {
            printf("The largest number : %d\n", max);
            continue;
        }

        if (input > max)
            max = input;
    }
    return 0;
}