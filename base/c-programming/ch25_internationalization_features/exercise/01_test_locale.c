/*
 * @author Anger
 * @date 2022/10/26
 * @brief 编写程序测试本地地区和 C 地区是否一样
 */
#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    char *locale_c = setlocale(LC_ALL, NULL);
    char *locale = setlocale(LC_ALL, "");

    if (strcmp(locale, locale_c) == 0)
        printf("current locale %s is the same as C locale %s\n", locale, locale_c);
    else
        printf("current locale %s is not the same as C locale %s\n", locale, locale_c);

    return 0;
}