/*
 * @author Anger
 * @date 2022/9/14
 * @brief 输入一个句子
 * 颠倒单词的顺序
 */
#include <stdio.h>
#include <stdbool.h>
#define SENTENCE_LEN 200

int main(void) {

    char ch, sentence[SENTENCE_LEN], *s = sentence;

    printf("Enter a sentence : ");

    bool terminated = false;
    while (!terminated && (ch = getchar()) != '\n') {
        switch (ch) {
            case '.': case '!': case '?':
                terminated = true;
                break;
            default:
                *s++ = ch;
                break;
        }
    }

    char *p = s, *q;

    while (--s >= sentence) {
        if (*s == ' ') {
            for (q = s + 1; q < p; q++)
                printf("%c", *q);
            printf(" ");
            p = s;
        } else if (s == sentence) {
            for (q = s; q <= p; q++)
                printf("%c", *q);
        }
    }

    return 0;
}
