/*
 * @author Anger
 * @date 2022/10/22
 * @brief 从文件中读取电话号码，并进行格式化
 * 每一行都包含一个电话号码
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char area[3+1], local[3+1], exact[4+1];
    char i = 0, c;
    bool complete = false;

    if (argc != 2) {
        fprintf(stderr, "用法 %s 文件名\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "文件打开失败 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = getc(fp)) != EOF) {
        if (isdigit(c) && i < 3)
            area[i++] = c;
        if (i == 3)
            area[i++] = '\0';
        else if (isdigit(c) && i > 3 && i < 7)
            local[i++ -4] = c;
        if (i == 7)
            local[i++ -4] = '\0';
        else if (isdigit(c) && i > 7 && i < 12)
            exact[i++ -8] = c;
        if (i == 12) {
            exact[i++ -8] = '\0';
            complete = true;
        }
        if (complete) {
            printf("(%s) %s-%s\n", area, local, exact);
            complete = false;
            i = 0;
        }
    }

    fclose(fp);

    exit(EXIT_SUCCESS);
}