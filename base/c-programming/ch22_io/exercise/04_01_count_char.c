/*
 * @author Anger
 * @date 2022/10/19
 * @brief 统计一个文本文件中的字符数量
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int count = 0;

    if (argc != 2) {
        printf("用法 ch_count 文件名\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    for (; getc(fp) != EOF; count++);

    printf("文件 %s 中的字符数量 %d\n", argv[1], count);
}