/*
 * @author Anger
 * @date 2022/9/17
 * @brief 对命令行输入的整数进行求和
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int sum = 0;

    while (--argc > 0)
        sum += atoi(argv[argc]);

    printf("Total => %d\n", sum);

    return 0;
}