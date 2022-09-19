/*
 * @author Anger
 * @date 2022/9/19
 * @brief 将单词存储在一个二位数组，每行存储一个单词
 * 假设单词数不超过 30 每个单词长度不超过 20 个字符
 */
#include <stdio.h>
#include <stdbool.h>

#define WORD_NUM 30
#define WORD_LEN 20

int main(void) {
    char sentence[WORD_NUM][WORD_LEN + 1], *p, ch;
    bool is_end = false;

    printf("Enter a sentence : ");

    int i;
    for (i = 0; i < WORD_NUM && !is_end; ++i) {
        p = sentence[i];
        while ((ch = getchar()) != ' ') {
            if (ch == '!' || ch == '.' || ch == '?' || ch == '\n') {
                is_end = true;
                break;
            }
            *p++ = ch;
        }
        *p = '\0';
        printf("%s", p);
    }

    while (i-- >= 0)
        printf("%s ", sentence[i]);

    return 0;
}