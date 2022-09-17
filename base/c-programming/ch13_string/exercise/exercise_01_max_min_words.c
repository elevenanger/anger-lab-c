/*
 * @author Anger
 * @date 2022/9/17
 * @brief 找出一组单词中按照字典序排序最大和最小的单词
 * 当用户输入四个字母的单词后，程序停止读入
 */
#include <stdio.h>
#include <string.h>
#define WORD_LEN 20

int main(void) {

    char smallest_word[WORD_LEN + 1], largest_word[WORD_LEN + 1];

    char s[WORD_LEN + 1];
    printf("Enter a words : ");
    scanf("%s", s);

    while (strlen(s) != 4) {
        if (strcmp(s, smallest_word) < 0)
            strcpy(smallest_word, s);
        if (strcmp(s, largest_word) > 0)
            strcpy(largest_word, s);
        printf("Enter a words : ");
        scanf("%s", s);
    }

    printf("smallest word => %s\n"
           "largest word  => %s\n",
           smallest_word, largest_word);

    return 0;
}