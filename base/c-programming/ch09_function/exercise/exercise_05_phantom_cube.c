/*
 * @author Anger
 * @date 2022/9/8
 */
#include <stdio.h>
#define MAGIC_NUM 99

void create_magic_square(int n, int magic_square[MAGIC_NUM][MAGIC_NUM]);
void print_magic_square(int n, int magic_square[MAGIC_NUM][MAGIC_NUM]);

void create_magic_square(int n, int magic_square[MAGIC_NUM][MAGIC_NUM]) {
    int row_val = 0, col_val;
    col_val = n / 2;

    for (int i = 1; i <= (n * n); ++i) {
        if (magic_square[row_val][col_val] != 0) {
            /* 复位 */
            row_val = (++row_val + n) % n;
            col_val = (--col_val + n) % n;
            /* 行号 + 1 */
            row_val = (++row_val + n) % n;
        }

        magic_square[row_val][col_val] = i;

        row_val = (--row_val + n) % n;
        col_val = (++col_val + n) % n;
    }
}

void print_magic_square(int n, int magic_square[MAGIC_NUM][MAGIC_NUM]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%3d", magic_square[i][j]);
        puts("");
    }
}

int main(void) {

    int size;
    int cube[MAGIC_NUM][MAGIC_NUM];

    for (int i = 0; i < MAGIC_NUM; ++i)
        for (int j = 0; j < MAGIC_NUM; ++j)
            cube[i][j] = 0;

    printf("Enter cube size : ");
    scanf("%d", &size);

    create_magic_square(size, cube);

    print_magic_square(size, cube);

    return 0;
}
