/*
 * @author Anger
 * @date 2022/9/6
 * @brief 打印 n * n 幻方
 */
#include <stdio.h>

int main(void) {

    /* 幻方尺寸 当前数字的行值 列值 */
    int size, row_val = 0, col_val;

    printf("Enter cube size : ");

    scanf("%d", &size);
    int cube[size][size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cube[i][j] = 0;

    /* 初始化幻方尺寸的二维数组 */
    col_val = size / 2;

    for (int i = 1; i <= (size * size); ++i) {
        if (cube[row_val][col_val] != 0) {
            /* 复位 */
            row_val = (++row_val + size) % size;
            col_val = (--col_val + size) % size;
            /* 行号 + 1 */
            row_val = (++row_val + size) % size;
        }

        cube[row_val][col_val] = i;

        row_val = (--row_val + size) % size;
        col_val = (++col_val + size) % size;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%3d", cube[i][j]);
        puts("");
    }

    return 0;
}