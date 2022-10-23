/*
 * @author Anger
 * @date 2022/10/23
 * @brief 将从标注输入的所有除了 \n 之外的空白字符替换为 ?
 * 输出到标准输出
 */
#include <stdio.h>
#include <string.h>

int main(void) {

    int c;

    while ((c = getchar()) != EOF) {
        if (strchr("\a\b\f\r\t\v", c) != NULL)
            putchar('?');
        else
            putchar(c);
    }

    return 0;
}