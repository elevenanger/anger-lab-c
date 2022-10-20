/*
 * @author Anger
 * @date 2022/10/19
 * @brief 使用字节和字符的形式显示文件的内容
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char b[10];
    unsigned long long int bytes_read, offset = 0;
    int i;

    if (argc != 2) {
        printf("用法：fbc 文件名\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(b, sizeof(char), 10, fp)) > 0) {
        printf("%6llu  ", offset);
        for (i = 0; i < 10; i++)
        {
            if (i >= bytes_read)
                printf("   ");
            else
                printf("%-3.2X", b[i]);
        }
        printf(" ");

        for (i = 0; i < bytes_read; i++)
            printf("%c", isprint(b[i]) ? b[i] : '.');
        printf("\n");
        offset += 10;
    }

    fclose(fp);

}