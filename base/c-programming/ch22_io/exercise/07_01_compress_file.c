/*
 * @author Anger
 * @date 2022/10/20
 * @brief 使用行程长度编码对文件内容进行压缩
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file_in, *file_out;
    char *out_file_name;
    unsigned char byte, next_byte, amount;
    long int position;

    if (argc != 2) {
        fprintf(stderr, "用法 %s 文件名\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file_in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    out_file_name = malloc(strlen(argv[1]) + 5);

    strcpy(out_file_name, argv[1]);
    strcat(out_file_name, ".rle");

    if ((file_out = fopen(out_file_name, "wb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", out_file_name);
        exit(EXIT_FAILURE);
    }

    free(out_file_name);

    while (fread(&byte, sizeof(unsigned char), 1, file_in) > 0) {
        amount = 1;
        position = ftell(file_in);
        while (fread(&next_byte, sizeof(unsigned char), 1, file_in) > 0
                && byte == next_byte) {
            amount++;
        }
        fwrite(&amount, sizeof(unsigned char), 1, file_out);
        fwrite(&byte, sizeof(unsigned char), 1, file_out);
        fseek(file_in, position + (amount - 1), SEEK_SET);
    }
    fclose(file_in);
    fclose(file_out);

    exit(EXIT_SUCCESS);
}