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

    for (int j = i - 1, k = 0; j >= 0; j--, k++) {
        if (sentence[j] == ' ' || j == 0) {
            for (int l = 0; k >= 0; l++, k--)
                printf("%c", sentence[j + l]);
        }
    }

    printf("%c", ch);

    return 0;
}