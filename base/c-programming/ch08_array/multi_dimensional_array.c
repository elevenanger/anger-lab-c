/*
 * @author Anger
 * @date 2022/9/5
 * @brief 多维数组
 */
#include <stdio.h>
#define N 5

/**
 * 打印多维数组
 * @param arr 多维数组
 */
void print_multi_dimensional_arr(int arr[N][N]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            printf("%d ", arr[row][col]);
        }
        puts("");
    }
    puts("");
}

/**
 * 定义多维数组
 * 数组可以有任意维数
 * int m[2][2] 声明一个二位数组，按照数学属于来说称之为矩阵
 * m 有 2 行 2 列
 * 数组的行和列的下标都是以 0 开始
 * 如果需要访问第 j 行 j 列的元素
 * 需要写成 m[i][j]
 * c 语言中按照主序存储数组
 * 也就是从第 0 行开始，接着第一行，以此类推
 * for 循环和一维数组紧密结合
 * 嵌套的 for 循环是处理多维数组的理想选择
 */
void declare_multi_dimensional_array() {
    int m[N][N] = {};
    print_multi_dimensional_arr(m);
}

/**
 * 初始化多维数组
 */
void initialize_multi_dimensional_array() {
    /* 使用多个一维数组的初始化式来初始化多维数组 */
    int m1[N][N] = {
            {1, 2, 3, 4, 5},
            {2, 2, 3, 4, 5},
            {3, 2, 3, 4, 5},
            {4, 2, 3, 4, 5},
            {5, 2, 3, 4, 5}};
    print_multi_dimensional_arr(m1);

    /*
     * 如果内层的数组没有大到足以满足一行
     * 那么把此行剩余的元素初始化为0
     */
    int m2[N][N] = {
            {1, 2, 3, 4, 5},
            {2, 2, 3, 4, 5},
            {3, 2, 3, 4, 5},
            {4}};
    print_multi_dimensional_arr(m2);

    /* C99 指定初始化式的方式也同样适用，未指定的元素将会默认置为 0 */
    int m3[N][N] = {
        [0][0] = 10, [1][1] = 11
    };
    print_multi_dimensional_arr(m3);
}

int main(void) {

    declare_multi_dimensional_array();

    initialize_multi_dimensional_array();

    return 0;
}