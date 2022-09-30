#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "read_line.h"

#define WORD_LEN 20
#define WORD_NUM 20

int word_sort(const void *w1, const void *w2);

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

    qsort(words, i, sizeof(words[0]), word_sort);

    for (int j = 0; j < i; ++j)
        printf("%s ", words[j]);

    return 0;
}

int word_sort(const void *w1, const void *w2) {
    return strcmp(*(char **)w1, *(char **)w2);
}
