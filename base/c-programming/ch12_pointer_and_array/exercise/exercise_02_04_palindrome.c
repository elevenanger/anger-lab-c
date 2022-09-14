/*
 * @author Anger
 * @date 2022/9/14
 * @brief 输入一条消息，检查这条消息是否是回文
 * 忽略所有不是字母的字符
 * 不检查大小写
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define ARR_NUM 100

void input_message(char *p, int *n);

bool is_palindrome(char *p, int n);

int main(void) {
    char a[ARR_NUM];
    int n = 0;
    input_message(a, &n);

    /* exercise_04 数组名作为指针 */
    if (is_palindrome(a, n))
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}

void input_message(char *p, int *n) {
    printf("Enter a message :");
    char ch;
    while ((ch = getchar()) != '\n' && *(n++) < ARR_NUM)
        if (toupper(ch) >= 'A' && toupper(ch) <= 'Z')
            *p++ = ch;
}

bool is_palindrome(char *p, int n) {
    for (char *q = p + n - 1; q - p > 0; q--, p++)
        if (toupper(*q) != toupper(*p))
            return false;
    return true;
}