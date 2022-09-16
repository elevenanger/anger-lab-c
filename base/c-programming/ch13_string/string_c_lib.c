/*
 * @author Anger
 * @date 2022/9/15
 * @brief c 语言中处理字符串的库
 * 对字符串进行复制、比较、拼接和截取子串等操作
 */
#include <stdio.h>
#include <string.h>

void copy_string(void);
void length_of_string(void);
void concat_string(void);
void compare_string(void);

int main(void) {
    copy_string();
    length_of_string();
    concat_string();
    compare_string();
    return 0;
}

/**
 * 复制字符串
 */
void copy_string(void) {
    /* 使用 strcpy() 函数复制字符串
     * strcpy() 无法检查复制的字符串大小是否符合目标字符串的大小 */
    char s[10], s2[10] = "string_2";
    strcpy(s, "string_1");
    printf("s => %s\n", s);
    strcpy(s, s2);
    printf("s => %s\n", s);
    strcpy(s, strcpy(s2, "string"));
    printf("s => %s\ns2=> %s\n", s, s2);

    /* strncpy() 复制字符串是一种更安全地复制方式
     * 它有第三个参数可以用于限制可复制的字符串
     * 如果复制的字符串比目标字符串长度 n 长，或者长度相同
     * 只能复制 n - 1 位
     * 最后一位留给空字符 */
    const char *s3 = "long string...";
    strncpy(s, s3, sizeof(s) - 1);
    s[sizeof(s) - 1] = '\0';
    printf("s => %s\n", s);
}

/**
 * 求字符串的长度
 */
void length_of_string(void) {
    const char *s1 = "string__1", s2[100] = "string__2";
    printf("length of s1 =>%ld\n", strlen(s1));
    printf("length of s2 =>%ld\n", strlen(s2));
    printf("length of \"\"  =>%ld\n", strlen(""));
}

/**
 * 拼接字符串
 */
void concat_string(void) {
    char s1[100], s2[100];
    strcpy(s2, "abcd");
    strcat(s1, s2);
    strcat(s1, "efg");
    printf("s1 => %s\n", s1);
    strcat(s1, strcat(s2, "h"));
    printf("s1 => %s\n", s1);

    /* 使用 strncat() 可以限制拼接复制的字符数量 */
    const char *s3 = "xxxx";
    strncat(s1, s3, strlen(s3));
    printf("s1 => %s\n", s1);
}

/**
 * 比较字符串
 */
void compare_string(void) {
    const char *s1 = "string__111", *s2 = "string__2", *s3 = "string__1";
    /* strcmp() 使用字典序进行比较
     * 通用规则：
     * 1、A-Z,a-z,0-9是连续的
     * 2、所有的大写字母都小于小写字母
     * 3、数字小于字母
     * 4、空格符小于所有打印字符(空格符码值是 32) */
    printf("compare s1 and s2 => %d\n", strcmp(s1, s2));
    printf("compare s1 and s3 => %d\n", strcmp(s1, s3));
}