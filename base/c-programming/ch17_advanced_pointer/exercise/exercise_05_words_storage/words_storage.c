#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "read_line.h"

#define WORD_LEN 20
#define WORD_NUM 20

int main(void) {

    char *word, *words[WORD_NUM];
    int i = 0;

    for (;;) {
        printf("Enter a word : ");
        word = malloc(WORD_LEN + 1);
        if (read_line(word, WORD_LEN) == 0)
            break;
        words[i++] = word;
    }

    char *temp;
    for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i - 1; ++k) {
            if (strcmp(words[k], words[k + 1]) > 0) {
                temp = words[k];
                words[k] = words[k + 1];
                words[k + 1] = temp;
            }
        }
    }

    for (int j = 0; j < i; ++j)
        printf("%s ", words[j]);

    return 0;
}
