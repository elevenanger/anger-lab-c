/*
 * @author Anger
 * @date 2022/10/22
 * @brief 凯撒加密
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main(void) {
    FILE *fp_in, *fp_out;
    char c, file_name[MAX_LEN], *out_file;
    int i, n, length;

    printf("输入需要加密的文件：");
    scanf("%s", file_name);
    if ((fp_in = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    out_file = malloc(sizeof(char) * strlen(file_name) + 5);
    strcpy(out_file, file_name);
    strcat(out_file, ".enc");

    if ((fp_out = fopen(out_file, "w")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", out_file);
        exit(EXIT_FAILURE);
    }

    printf("输入偏移量 (1 - 26) : ");
    scanf("%d", &n);
    while ((c = getc(fp_in)) != EOF) {
        if (c >= 'a' && c <= 'z')
            putc((((c - 'a') + n) % 26 + 'a'), fp_out);
        else if (c >= 'A' && c <= 'Z')
            putc((((c - 'A') + n) % 26 + 'A'), fp_out);
        else
            putc(c, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    exit(EXIT_SUCCESS);
}