#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "read_line.h"

#define WORD_LEN 20
#define WORD_NUM 20

int sort_word(const void *w1, const void *w2);

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

    qsort(words, i, sizeof(word), sort_word);

    for (int j = 0; j < i; ++j)
        printf("%s\n", words[j]);

    return 0;
}

int sort_word(const void *w1, const void *w2) {
    const char *word_1 = w1;
    const char *word_2 = w2;

    return strcmp(word_1, word_2);
}
