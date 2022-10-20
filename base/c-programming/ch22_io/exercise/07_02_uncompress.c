/*
 * @author Anger
 * @date 2022/10/20
 * @brief 使用行程编码解码文件
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *file_in, *file_out;
    char *out_file;
    unsigned char byte, amount, i;
    long int position = 0;

    if (argc != 2) {
        fprintf(stderr, "用法 %s 压缩文件\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strstr(argv[1], ".rle") == NULL) {
        fprintf(stderr, "文件名必须以 .rle 结尾\n");
        exit(EXIT_FAILURE);
    }

    if ((file_in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    out_file = malloc(strlen(argv[1]) - 4);
    strncpy(out_file, argv[1], strlen(argv[1]) - 4);

    if ((file_out = fopen(out_file, "wb")) == NULL) {
        fprintf(stderr, "无法打打开文件 %s\n", out_file);
        exit(EXIT_FAILURE);
    }
    free(out_file);

    while (fread(&byte, sizeof(unsigned char), 1, file_in) > 0) {
        if (position % 2 == 0)
            amount = byte;
        else {
            for (i = 0; i < amount; ++i)
                fwrite(&byte, sizeof(unsigned char), 1, file_out);
        }
         position++;
    }
    fclose(file_in);
    fclose(file_out);

    exit(EXIT_SUCCESS);
}