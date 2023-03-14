/*
 * @author Anger
 * @date 2023/3/14
 * @brief 将文本文件读取为 ASCII 字符
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CHAR_NUM 16

int read_str(char str[], int n, FILE *file);

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = malloc(sizeof(char) * CHAR_NUM);

    if (argc != 2) {
        fprintf(stderr, "用法 csapp_01_read_file_to_ascii file");
        exit(EXIT_FAILURE);
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "无法打开文件 => %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_str(line, CHAR_NUM, file) > 0) {
        for (int i = 0; i < CHAR_NUM && line[i] != '\0'; ++i)
            printf("%4d", line[i]);
        printf("\n");
    }


    fclose(file);

    exit(EXIT_SUCCESS);
}

int read_str(char str[], int n, FILE *file) {
    int ch, i = 0;

    while (i < n && (ch = getc(file)) != EOF)
        str[i++] = ch;

    str[i] = '\0';
    return i;
}

