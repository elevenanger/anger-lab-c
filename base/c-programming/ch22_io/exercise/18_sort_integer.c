/*
 * @author Anger
 * @date 2022/10/22
 * @brief 从文件中读取整数
 * 整数的个数不超过 10000 个
 * 对读取的整数进行排序
 * 显示文件中整数的最大值、最小值和中位数
 * 如果是偶数个整数，中间会有两个整数
 * 则取它们的平均值
 */
#include <stdlib.h>
#include <stdio.h>

#define LIMITS_NUN 10000

int compare(const void *a, const void *b);

int main(int argc, char *argv[]) {
    FILE *fp;
    int nums[LIMITS_NUN], min_num, mid_num, max_num, i = 0;

    if (argc != 2) {
        fprintf(stderr, "用法 %s 输入文件名\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "文件打开失败 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (!feof(fp) && i < LIMITS_NUN)
        fscanf(fp, " %d", &nums[i++]);
    i--;

    qsort(nums, i, sizeof(int), compare);

    max_num = nums[0];
    min_num = nums[i - 1];
    if (i % 2 == 0)
        mid_num = (nums[(i - 1) / 2] + nums[(i - 1) / 2 + 1]) / 2;
    else
        mid_num = nums[(i - 1) / 2];


    printf("max number => %d\n"
           "mid number => %d\n"
           "min number => %d\n",
           max_num, mid_num, min_num);

    fclose(fp);
    exit(EXIT_SUCCESS);
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
