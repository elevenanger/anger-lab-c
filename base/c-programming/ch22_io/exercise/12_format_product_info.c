/*
 * @author Anger
 * @date 2022/10/22
 * @brief 从文件中读取一系列数据，格式化产品信息
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LEN 50

int read_str(char str[], int n, FILE *file);

int main(int argc, char *argv[]) {
    FILE *fp;
    int item_number, year, month, day;
    float price;
    char line[LINE_LEN];

    if (argc != 2) {
        fprintf(stderr, "用法 12_format_product_info 文件名");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "文件打开失败 => %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item      \tUnit      \tPurchase  \n"
           "          \tPrice     \tDate      \n");
    while (read_str(line, LINE_LEN, fp) > 0) {
        sscanf(line, "%d,%f,%d/%d/%d",
               &item_number, &price, &month, &day, &year);
        printf("%-10d\t$%9.2f\t%02d/%2d/%4d\n",
               item_number, price, month, day, year);
    }

    exit(EXIT_SUCCESS);
}

int read_str(char str[], int n, FILE *file) {
    int ch, i = 0;
    while (isspace(ch = getc(file)));

    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getc(file);
    }

    str[i] = '\0';
    return i;
}
