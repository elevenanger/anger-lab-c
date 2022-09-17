/*
 * @author Anger
 * @date 2022/9/17
 * @brief 计算一个单词中的元音字母数量
 */
#include <stdio.h>
#include <ctype.h>


int compute_vowel_count(const char *sequence);

int main(void) {

    char string[20];

    printf("Enter a sentence : ");
    scanf("%s", string);

    printf("Your sentence contains %d vowels", compute_vowel_count(string));

    return 0;
}

int compute_vowel_count(const char *sequence) {

    char ch, count = 0;

    while ((ch = *sequence++) != '\0') {
        switch (toupper(ch)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count += 1;
                break;
            default:
                continue;
        }
    }


    return count;
}