/*
 * @author Anger
 * @date 2022/9/6
 * @brief 测试两个单词是否为变位词 （相同字母重新排列）
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

int main(void) {

    bool anagram = true;
    char c;
    /* 指定一个长度为字母数量的数组，初始值全部设置为0 */
    int alpha_digit[26] = {};

    printf("Enter first word : ");

    while ((c = (char)getchar()) != '\n') {
        /* 读取用户输入的字符，如果不是字母则跳过 */
        if (!isalpha(c)) continue;
        /* 转换成小写 - 'a' 则代表字母在数组中的指定位数，为当前位数加一 */
        alpha_digit[tolower(c) - 'a']++;
    }

    printf("Enter second word : ");
    while ((c = (char)getchar()) != '\n') {
        if (!isalpha(c)) continue;
        /* 第二个单词反过来给指定位数减去 1*/
        alpha_digit[tolower(c) - 'a']--;
    }

    /* 遍历数组，如果有不为 1 的位，终止循环，非变位词 */
    for (int i = 0; i < SIZE(alpha_digit); ++i) {
        if (alpha_digit[i] != 0) {
            anagram = false;
            break;
        }
    }

    if (anagram)
        printf("The word are anagrams.");
    else
        printf("The word are not anagrams.");

    return 0;
}