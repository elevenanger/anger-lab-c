/*
 * @author Anger
 * @date 2022/10/18
 * @brief 格式化的输入/输出
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"

/* ..printf 类函数 */
void printf_func(void);

void scanf_func(void);
/* 错误检查与文件末尾检查 */
void error_check_and_end_check(void);

int main(void) {

    printf_func();

    scanf_func();

    error_check_and_end_check();

    return 0;
}

void printf_func(void) {
    FILE *fp = fopen(FILE_PATH, "a");
    int total = 100;

    /* printf 和 fprintf 唯一的区别是 printf 始终指向 stdout
     * fprintf 可以将数据写入任何的输出流 */
    printf("Date: %s, Total %d\n", __DATE__, total);
    fprintf(fp, "Date: %s, Total %d\n", __DATE__, total);
    fclose(fp);
}

void scanf_func(void) {
    char *s = malloc(100);
    FILE *fp = fopen(FILE_PATH, "r");

    while (fscanf(fp, "%s", s) != EOF)
        printf("%s", s);

    fclose(fp);

    puts("");
}

void error_check_and_end_check(void) {
    FILE *fp = fopen(FILE_PATH, "r");
    int n;

    if (fp == NULL)
        return;

    while (fscanf(fp, "%d", &n) != EOF) {
        /* 每个流都有与之相关的两个指示器：
         * 错误指示器
         * 文件末尾指示器
         * 打开流时会清除这些指示器
         * 一旦设置了错误指示器或者文件末尾指示器
         * 它就会保持这种状态直到被显式地清除 */
        if (ferror(fp)) {
            fclose(fp);
            return;
        }
        if (feof(fp)) {
            fclose(fp);
            return;
        }
        /* 跳过全部字符直到下一个换行符 */
        fscanf(fp, "%*[^\n]");
    }
    /* clearerr() 函数会同时清除错误指示器和文件末尾指示器 */
    clearerr(fp);
    fclose(fp);
    printf("找到的整数:%d\n", n);
}
