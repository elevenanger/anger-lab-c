/*
 * @author Anger
 * @date 2022/10/19
 * @brief 将任意数量的文件写到标准输出
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    int ch, fail_count = argc - 1;

    if (argc < 2) {
        printf("用法 fcat 文件1 文件2 ... 文件n\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i) {
        fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("无法打开文件 %s\n", argv[i]);
            fclose(fp);
            continue;
        }

        fail_count--;

        while ((ch = getc(fp)) != EOF)
            fputc(ch, stdout);

        fclose(fp);
    }

    if (fail_count != 0) {
        fprintf(stderr, "错误：文件都无法打开\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);

}