/*
 * @author Anger
 * @date 2022/10/19
 * @brief 进行异或加密
 */
#include <stdlib.h>
#include <stdio.h>
#define KEY '&'

int main(int argc, char *argv[]) {

    FILE *src, *dest;

    int ch;

    if (argc != 3) {
        printf("用法 xor 源文件 目标文件\n");
        exit(EXIT_FAILURE);
    }

    if ((src = fopen(argv[1], "rb")) == NULL) {
        printf("无法打开源文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest = fopen(argv[2], "wb")) == NULL) {
        printf("无法打开目标文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch ^ KEY, dest);
    }

    fclose(src);
    fclose(dest);
}