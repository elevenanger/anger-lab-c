/*
 * @author Anger
 * @date 2022/9/24
 * @brief 读取一行的字符为字符串
 */
#include <stdio.h>
#include <ctype.h>
#include "read_line.h"

int read_line(char str[], int n) {
    int ch, i = 0;
    /* 忽略空白字符 */
    while (isspace(ch = getchar()));

    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}