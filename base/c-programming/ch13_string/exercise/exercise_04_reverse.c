/*
 * @author Anger
 * @date 2022/9/17
 * @brief 逆序输出命令行输入的参数
 */
#include <stdio.h>

int main(int argc, char *argv[]) {

    while (argc-- > 1)
        printf("%s ", argv[argc]);

    return 0;
}