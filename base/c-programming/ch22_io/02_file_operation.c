/*
 * @author Anger
 * @date 2022/10/17
 * @brief 文件操作
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"
#define FILE_PATH_D "/Users/liuanglin/data/tmp/d.dat"

/* 打开文件 */
void open_file(void);
/* 关闭文件 */
void close_file(void);
/* 未打开的流附加文件 */
void attach_file_for_opened_stream(void);

int main(void) {
    return 0;
}

void open_file(void) {
    /* 将文件用作流打开时需要使用 fopen 函数
     * fopen 函数有两个参数
     * 第一个参数是打开文件名的字符串
     * 第二个参数是"模式字符串"，用来指定打算对文件执行的操作
     * fopen 函数返回一个文件指针
     * 程序将该文件指针存储在一个变量中
     * 稍后需要对文件进行操作的时候使用它
     * 无法打开文件则会返回一个空指针
     * 以下是打开文本文件的模式 */
    fopen(FILE_PATH, "r"); /* r 打开文件用于读 */
    fopen(FILE_PATH, "w"); /* w 打开文件用于写 */
    fopen(FILE_PATH, "wx"); /* wx 创建文件用于写（文件不能已存在）*/
    fopen(FILE_PATH, "w+x"); /* w+x 创建文件用于更新（文件不能已存在）*/
    fopen(FILE_PATH, "a"); /* a 打开文件用于追加（文件可以已存在）*/
    fopen(FILE_PATH, "r+"); /* r+ 打开文件用于读和写，从文件头开始 */
    fopen(FILE_PATH, "w+"); /* w+ 打开文件用于读和写，如果文件存在就截去 */
    fopen(FILE_PATH, "a+"); /* a+ 打开文件用于读和写（如果文件存在就追加）*/

    /* 以下是打开二进制文件的模式 */
    fopen(FILE_PATH, "rb"); /* 打开文件用于读 */
    fopen(FILE_PATH, "wb"); /* 打开文件用于写 */
    fopen(FILE_PATH, "wbx"); /* 打开文件用于写,文件不能是已存在 */
    fopen(FILE_PATH, "ab"); /* 打开文件用于追加 */
    fopen(FILE_PATH, "r+b"); /* 打开文件用于读和写，从文件头开始 */
    fopen(FILE_PATH, "w+b"); /* 打开文件用于更新，如果文件存在就截去 */
    fopen(FILE_PATH, "w+bx"); /* 打开文件用于更新，文件不能已存在 */
    fopen(FILE_PATH, "a+b"); /* 打开文件用于更新（如果文件存在就追加）*/
}

void close_file(void) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        printf("Can't open file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
    /* 使用 fclose() 函数关闭文件
     * 如果文件正常关闭 fclose() 函数返回 0
     * 否则会返回错误代码 EOF */
    int closed = fclose(fp);
    if (closed == EOF) {
        printf("Can't close file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
}

void attach_file_for_opened_stream(void) {
    FILE *fp1 = fopen(FILE_PATH, "r");
    if (fp1 == NULL) {
        printf("Can't open file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
    /* freopen 为已经打开的流附件一个不同的文件 */
    if (freopen(FILE_PATH_D, "w", fp1) == NULL) {
        printf("Can't open file => %s\n", FILE_PATH_D);
        exit(EXIT_FAILURE);
    }
}
