/*
 * @author Anger
 * @date 2022/10/18
 * @brief 复制文件
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *source_file, *dest_file;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "用法：fcopy 源文件 目标文件\n");
        exit(EXIT_FAILURE);
    }

    if ((source_file = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_file = fopen(argv[2], "wb")) == NULL) {
        fclose(source_file);
        fprintf(stderr, "无法打开文件 %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_file)) != EOF)
        putc(ch, dest_file);

    fclose(source_file);
    fclose(dest_file);
    return 0;
}