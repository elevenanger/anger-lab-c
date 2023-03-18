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

char *transform_space_chars(char c);

void print_ascii(const char *str);

void print_char(const char *str);

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
        print_ascii(line);
        print_char(line);
    }

    fclose(file);
    free(line);

    exit(EXIT_SUCCESS);
}

int read_str(char str[], int n, FILE *file) {
    int ch, i = 0;

    while (i < n && (ch = getc(file)) != EOF)
        str[i++] = (char)ch;

    str[i] = '\0';
    return i;
}

char* transform_space_chars(char c) {
    char *chars;

    switch (c) {
        case '\n': chars = "\\n"; break;
        case '\t': chars = "\\t"; break;
        case ' ' : chars = "SP";  break;
        case '\v': chars = "\\v"; break;
        case '\r': chars = "\\r"; break;
        case '\f': chars = "\\f"; break;
        default: chars = NULL;
    }

    return chars;
}

void print_ascii(const char *str) {
    char c;
    while ((c = *str++) != '\0')
        printf("%5d", c);
    printf("\n");
}

void print_char(const char *str) {
    char c;
    char *s;

    while ((c = *str++) != '\0') {
        if (isspace(c)) {
            s = transform_space_chars(c);
            printf("%5s", s);
        } else
            printf("%5c", c);
    }

    printf("\n");
}