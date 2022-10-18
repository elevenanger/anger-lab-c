/*
 * @author Anger
 * @date 2022/10/18
 * @brief 块的输入和输出
 */
#include <stdio.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"

/* 从内存中将数据块的数据写入 stream */
void write_block(void);
/* 从 stream 中读取数据到内存中 */
void read_block(void);

int main(void) {
    write_block();
    read_block();
    return 0;
}

void write_block(void) {
    int a[100], n;
    for (int i = 0; i < 100; ++i) {
        a[i] = i;
    }
    FILE *fp = fopen(FILE_PATH, "wb");
    n = fwrite(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
    printf("%d\n", n);
    fclose(fp);
}

void read_block(void) {
    FILE *fp = fopen(FILE_PATH, "rb");
    int a[100],
    n = fread(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    fclose(fp);
}
