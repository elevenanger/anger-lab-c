/*
 * @author Anger
 * @date 2022/10/19
 * @brief 统计文件中的行数
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch, count = 0;

    if (argc != 2) {
        printf("用法 words_count 文件名\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            count++;
    }

    printf("文件 %s 中的行数量 %d\n", argv[1], count);

    fclose(fp);
    exit(EXIT_SUCCESS);
}
