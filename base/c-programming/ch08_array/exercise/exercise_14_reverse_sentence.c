/*
 * 输入一个句子
 * 颠倒句子中单词的顺序
 */
#include <stdio.h>
#include <stdbool.h>
#define SENTENCE_LEN 200

int main(void) {

    int i = 0;
    char ch;
    char sentence[SENTENCE_LEN];

    printf("Enter a sentence : ");

    bool terminated = false;
    while (!terminated && (ch = getchar()) != '\n') {
        switch (ch) {
            case '.': case '!': case '?':
                terminated = true;
                break;
            default:
                sentence[i] = ch;
                i++;
        }
    }

    for (int j = i - 1; j >= 0; j--) {
        if (sentence[j] == ' ') {
            for (int l = j + 1; l < i; l++)
                printf("%c", sentence[l]);
            i = j;
            printf(" ");
        }
        if (j == 0) {
            for (int l = j; l < i; l++)
                printf("%c", sentence[l]);
        }
    }

    printf("%c", ch);

    return 0;
}