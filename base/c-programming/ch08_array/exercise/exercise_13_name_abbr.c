/*
 * 修改 7-11
 * 在输出前面加上标签
 */
#include <stdio.h>
#define LASTNAME_LEN 20

int main(void) {

    /* 变量 ch 用于存储当前字符，first_name 用于存储 first_name 第一个字符 */
    unsigned int ch, first_name = 0, i = 0;
    char last_name[LASTNAME_LEN];

    printf("Enter a name : ");
    /* 字符不为空格之前输入的都是 first_name */
    while ((ch = getchar())) {
        /* 跳过前面的空格 */
        if (!first_name && ch == ' ') continue;
        /* first_name 只取第一个非空格字符进行赋值 */
        if (!first_name) first_name = ch;
        /* first_name 赋值后遇到空格则结束循环 */
        if (ch == ' ') break;
    }

    /* 在换行之前，剩下的字符都是 last_name */
    while ((ch = getchar()) != '\n') {
        /* 跳过空白字符 */
        if (ch == ' ' || ch == '\b' ||
            ch == '\t' || ch == '\v')
            continue;
        last_name[i] = (char) ch;
        i++;
    }

    printf("You entered the name : ");
    for (int j = 0; j < i; ++j)
        printf("%c", last_name[j]);

    /* 按要求输入 first_name 第一个字符以及其它的字符 */
    printf(", %c.", (char) first_name);

    return 0;
}
