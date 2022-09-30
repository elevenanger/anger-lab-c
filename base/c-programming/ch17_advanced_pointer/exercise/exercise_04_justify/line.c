/*
 * @author Anger
 * @date 2022/9/22
 * @brief 对行数据进行操作
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word_node {
    char word[20];
    struct word_node *next_word;
};

struct word_node* line = NULL;
int line_len = 0;
int num_words = 0;


void clear_line(void) {
    struct word_node *temp;
    while (line != NULL) {
        temp = line;
        line = line->next_word;
        free(temp);
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    struct word_node **p_line = &line;
    struct word_node* new_word = malloc(sizeof(struct word_node) + strlen(word) + 1);
    if (new_word == NULL) {
        printf("error in malloc new word\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_word->word, word);
    new_word->next_word = NULL;

    while (*p_line != NULL)
        p_line = &(*p_line)->next_word;
    *p_line = new_word;
    line_len += strlen(word);
    if (num_words > 0)
        line_len++;
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert, i;
    int char_count = 0;
    struct word_node *entry = line;
    extra_spaces = space_remaining();

    while (char_count < line_len && entry != NULL) {
        printf("%s", entry->word);
        if (num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (i = 1; i <= spaces_to_insert + 1; i++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
        }
        char_count += strlen(entry->word) + 1;
        num_words--;
        entry = entry->next_word;
    }
    putchar('\n');
}

void flush_line(void) {
    int i;
    struct word_node *entry = line;
    if (line_len > 0) {
        for (i = 0; entry != NULL; ++i, entry = entry->next_word) {
            if (i > 0 && entry->next_word != NULL)
                putchar(' ');
            printf("%s ", entry->word);
        }
    }
    printf("\n");
    clear_line();
}