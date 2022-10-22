/*
 * @author Anger
 * @date 2022/10/22
 * @brief 将 Windows 格式文件转换为 Unix 格式文件
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    char c;

    if (argc != 3) {
        fprintf(stderr, "用法 %s 输入文件 输出文件\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp_in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp_out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = getc(fp_in)) != EOF) {
        if (c != '\x0d' && c != '\x1a')
            fputc(c, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    exit(EXIT_SUCCESS);
}