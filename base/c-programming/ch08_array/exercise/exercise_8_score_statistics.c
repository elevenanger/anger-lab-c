/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 exercise_7
 * 提示用户输入每个学生 5 门课程的成绩
 * 一共有 5 个学生
 * 计算每个学生的总分和平均分
 * 以及没门测验的平均分、高分和低分
 */
#include <stdio.h>
#include <limits.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))
/* 学生数量 */
#define STU_NUM 5
/* 课程数量 */
#define LES_NUM 5
/* 数组矩阵的当前元素 */
#define CUR_ELE(arr) arr[i][j]

int main(void) {

    int matrix[STU_NUM][LES_NUM] = {};
    int stu_les_sum[STU_NUM] = {};
    int les_stu_sum[LES_NUM] = {};
    int les_high_score[LES_NUM] = {};
    int les_low_score[LES_NUM] = {};

    /* 初始化课程最小值数组中每个元素的值为 int 最大值 */
    for (int i = 0; i < SIZE(les_low_score); ++i)
        les_low_score[i] = INT_MAX;

    for (int i = 0; i < STU_NUM; ++i) {
        printf("Enter row %d : ", i + 1);
        for (int j = 0; j < LES_NUM; ++j) {
            scanf("%d", &CUR_ELE(matrix));
            stu_les_sum[i] += CUR_ELE(matrix);
            les_stu_sum[j] += CUR_ELE(matrix);
            if (les_low_score[j] > CUR_ELE(matrix))
                les_low_score[j] = CUR_ELE(matrix);
            if (les_high_score[j] < CUR_ELE(matrix))
                 les_high_score[j] = CUR_ELE(matrix);
        }
    }

    printf("\nstudent average score : ");
    for (int i = 0; i < STU_NUM; ++i)
        printf("%.2f ", (float) stu_les_sum[i] / STU_NUM);

    printf("\nlesson average score : ");
    for (int i = 0; i < LES_NUM; ++i)
        printf("%.2f ", (float) les_stu_sum[i] / LES_NUM);

    printf("\nlesson highest score : ");
    for (int i = 0; i < LES_NUM; ++i)
        printf("%d ", les_high_score[i]);

    printf("\nlesson lowest score : ");
    for (int i = 0; i < LES_NUM; ++i)
        printf("%d ", les_low_score[i]);

    return 0;
}
