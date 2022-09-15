/*
 * @author Anger
 * @date 2022/9/15
 * @brief 访问字符串中的字符
 */
#include <stdio.h>

void access_char_by_array_index(const char s[]);

void access_char_by_pointer_arithmetic(const char s[]);

int main(void) {
    access_char_by_pointer_arithmetic("string");
    access_char_by_array_index("string");
    return 0;
}

/**
 * 字符串是以字符数组的方式存储的
 * 通过数组下标来访问字符串中的字符
 * @param s 字符串
 */
void access_char_by_array_index(const char s[]) {
    for (int i = 0; s[i] != '\0'; ++i)
        printf("%c", s[i]);
}

/**
 * 访问字符串中的字符
 * 使用指针算数运算的方式访问字符串中的元素
 */
void access_char_by_pointer_arithmetic(const char s[]) {
    const char *a = s;
    while (*a != '\0')
        printf("%c", *a++);
}
