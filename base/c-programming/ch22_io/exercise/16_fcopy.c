/*
 * @author Anger
 * @date 2022/10/22
 * @brief 使用 fread 和 fwrite 来复制文件
 * 复制时使用 512 字节的块
 */
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {

    FILE *source_file, *dest_file;
    char buffer[BLOCK_SIZE];
    int read;

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


    while ((read = fread(buffer, 1, BLOCK_SIZE, source_file)) > 0)
        fwrite(buffer, 1, read, dest_file);

    fclose(source_file);
    fclose(dest_file);
    return 0;
}
