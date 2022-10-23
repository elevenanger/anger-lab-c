/*
 * @author Anger
 * @date 2022/10/23
 * @brief 从标准输入拷贝文本到标准输出
 * 删除每行开头的空白字符
 * 删除全部是空白字符的行
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    bool read_to_copy = false;
    char c;

    while ((c = getchar()) != EOF) {
        if (read_to_copy)
            putchar(c);
        else if (!isspace(c)) {
            read_to_copy = true;
            putchar(c);
        }

        if (c == '\n')
            read_to_copy = false;
    }

    return 0;
}