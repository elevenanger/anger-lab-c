/*
 * @author Anger
 * @date 2022/10/18
 * @brief 字符的输入与输出
 */
#include <stdio.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"

/* 输出函数 */
void output_func(void);
/* 输入函数 */
void input_func(void);

int main(void) {

    output_func();

    input_func();

    return 0;
}

void output_func(void) {
    char c = 'a';
    FILE *fp = fopen(FILE_PATH, "wb");
    /* putchar 函数向 stdout 写一个字符 */
    putchar(c);
    /* putc 函数向任意流写一个字符
     * fputc 函数也是向任意流写一个字符
     * putc 通常作为宏来实现
     * fputc 只作为函数实现
     * 如果出现了写错误
     * 这三个函数都会返回 EOF 并为流设置错误指示器
     * 否则返回写入的字符 */
    putc(c, fp);
    fputc(c, fp);
}

void input_func(void) {
    FILE *fp = fopen(FILE_PATH, "rb");
    int c;
    /* getchar() 从 stdin 读取一个字符 */
    c = getchar();
    printf("c => %d\n", c);
    c = fgetc(fp);
    printf("c => %d\n", c);
    c = getc(fp);
    printf("c => %d\n", c);
    c = ungetc(c, fp);
    printf("c => %d\n", c);
}
