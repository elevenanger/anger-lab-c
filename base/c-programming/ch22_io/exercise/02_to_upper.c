/*
 * @author Anger
 * @date 2022/10/19
 * @brief 从命令行中读取文件
 * 将文件中的所有字母转换成大写
 * 写入 stdout
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int c;

    if (argc != 2) {
        printf("用法 : upper 文件名\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
            fputc(toupper(c), stdout);
        else
            fputc(c, stdout);
    }

    fclose(fp);
}