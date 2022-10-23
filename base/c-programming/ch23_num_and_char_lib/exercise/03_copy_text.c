/*
 * @author Anger
 * @date 2022/10/23
 * @brief 从标准输入拷贝到标准输出
 * 每个单词首字母大写
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    bool in_word = false;
    char c;

    while ((c = getchar()) != EOF) {
        if (isalpha(c) && !in_word) {
            putchar(toupper(c));
            in_word = true;
        } else if (isspace(c)) {
            in_word = false;
            putchar(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}
