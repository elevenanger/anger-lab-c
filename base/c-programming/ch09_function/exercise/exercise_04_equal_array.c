/*
 * @author Anger
 * @date 2022/9/8
 * @brief 将输入的信息转换为 b1ff 公告
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))
#define CHAR_NUM 26
void read_word(int counts[CHAR_NUM]);
bool equal_array(int counts1[CHAR_NUM], int counts2[CHAR_NUM]);

void read_word(int counts[CHAR_NUM]) {
    char c;
    while ((c = (char)getchar()) != '\n') {
        if (!isalpha(c)) continue;
        counts[tolower(c) - 'a']++;
    }
}


bool equal_array(int counts1[CHAR_NUM], int counts2[CHAR_NUM]) {
    bool is_anagram = true;
    for (int i = 0; i < CHAR_NUM; ++i) {
        if (counts1[i] != counts2[i]) {
            is_anagram = false;
            break;
        }
    }
    return is_anagram;
}

int main(void) {

    bool anagram = true;
    char c;
    /* 指定一个长度为字母数量的数组，初始值全部设置为0 */
    int alpha_digit1[26] = {}, alpha_digit2[26] = {};

    printf("Enter first word : ");
    read_word(alpha_digit1);

    printf("Enter second word : ");
    read_word(alpha_digit2);


    if (equal_array(alpha_digit1, alpha_digit2))
        printf("The word are anagrams.");
    else
        printf("The word are not anagrams.");

    return 0;
}