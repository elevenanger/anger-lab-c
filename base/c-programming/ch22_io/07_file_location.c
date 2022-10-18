/*
 * @author Anger
 * @date 2022/10/18
 * @brief 文件定位
 */
#include <stdio.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"

/* 改变文件位置 */
void file_seek(void);
/* 获取文件当前位置 */
void current_pos(void);
/* 重置文件位置为起始位置 */
void reset_file(void);
/* 处理大文件 */
void huge_file(void);

int main(void) {

    file_seek();

    current_pos();

    reset_file();

    return 0;
}

void file_seek(void) {
    /* fseek 改变文件位置
     * 第一个参数是需要改变的文件指针
     * 第二个参数是字节计数，如果是正数则往后移动
     * 如果是负数则往前移动
     * 第三个参数是文件偏移量宏
     * SEEK_SET 文件起始处
     * SEEK_CUR 文件的当前位置
     * SEEK_END 文件末尾 */
    FILE *fp = fopen(FILE_PATH, "rb");
    int a[100], n;
    fseek(fp, 10 * sizeof(a[0]), SEEK_SET);
    n = fread(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
    printf("%d\n", n);
    fseek(fp, -10 * sizeof(a[0]), SEEK_END);
    n = fread(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
    printf("%d\n", n);
    fclose(fp);
}

void current_pos(void) {
    FILE *fp = fopen(FILE_PATH, "rb");
    fseek(fp, 10 * sizeof(int), SEEK_SET);
    /* ftell() 函数返回文件当前位置
     * 如果是字节流返回的是字节数
     * 但是如果是文本流返回的不一定是字节数 */
    printf("当前位置 : %ld\n", ftell(fp));
    fclose(fp);
}

void reset_file(void) {
    FILE *fp = fopen(FILE_PATH, "rb");
    fseek(fp, 20, SEEK_SET);
    printf("当前位置 : %ld\n", ftell(fp));
    /* rewind 函数把文件位置设置在起始处
     * 并且清除文件的错误指示器 */
    rewind(fp);
    printf("当前位置 : %ld\n", ftell(fp));
    fclose(fp);
}

void huge_file(void) {
    fpos_t file_pos;
    FILE *fp = fopen(FILE_PATH, "rb");
    /* 使用 fgetpos() 和 fsetpos() 处理大文件 */
    fgetpos(fp, &file_pos);
    fsetpos(fp, &file_pos);
    fclose(fp);
}
