/*
 * @author Anger
 * @date 2022/9/22
 * @brief 格式化单词文本
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word.h"
#include "line.h"
#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    char word[MAX_WORD_LEN + 2];
    int word_len;

    if (argc != 3) {
        fprintf(stderr, "用法 ch22_15_justify 输入文件 输出文件\n");
        exit(EXIT_FAILURE);
    }

    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "文件打开失败 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "文件打开失败 %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    clear_line();

    for (;;) {
        word_len = read_word(word, MAX_WORD_LEN + 1, fp_in);
        if (word_len == 0) {
            flush_line(fp_out);
            break;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line(fp_out);
            clear_line();
        }
        add_word(word);
    }

    fclose(fp_in);
    fclose(fp_out);

    exit(EXIT_SUCCESS);
}