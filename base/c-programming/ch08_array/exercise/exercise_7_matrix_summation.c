/*
 * @author Anger
 * @date 2022/9/5
 * @brief 程序读取一个 5 * 5 的数组
 * 显示每行与每列的和
 */
#include <stdio.h>
#define ROW_NUM 5
#define COL_NUM 5

int main(void) {

    int matrix[ROW_NUM][COL_NUM] = {};
    int row_sums[ROW_NUM] = {};
    int col_sums[COL_NUM] = {};

    for (int i = 0; i < ROW_NUM; ++i) {
        printf("Enter row %d : ", i + 1);
        for (int j = 0; j < COL_NUM; ++j) {
            scanf("%d", &matrix[i][j]);
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];
        }
    }

    printf("\nRow totals : ");
    for (int i = 0; i < ROW_NUM; ++i)
        printf("%d ", row_sums[i]);

    printf("\nCol totals : ");
    for (int i = 0; i < COL_NUM; ++i)
        printf("%d ", col_sums[i]);

    return 0;
}