/*
 * @author Anger
 * @date 2022/9/27
 * @brief 动态分配数组
 */
#include <stdio.h>
#include <stdlib.h>

void allocation_with_malloc(int n);
void allocation_with_calloc(int n);
void allocation_with_realloc(int n);

int main(void) {

    allocation_with_malloc(10);

    allocation_with_calloc(10);

    allocation_with_realloc(5);
}

/**
 * 使用 malloc 为数组分配内存空间
 */
void allocation_with_malloc(int n) {
    int *a;
    a = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

/**
 * 使用 calloc 分配内存空间
 * @param n 元素数量
 */
void allocation_with_calloc(int n) {
    int *a;
    /* calloc(count，size）接收两个参数
     * count 和 size
     * count 是元素数量
     * size 是每个元素的大小
     * calloc 会通过把所有位设置为 0 来进行初始化 */
    a = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    puts("");
}

/**
 * 重新分配内存空间
 * 扩展内存块时 realloc 不对新添加的内存块进行初始化
 * 如 realloc 不能扩展内存块则会返回空指针
 * 使用 realloc 重新分配内存块
 * 一定要对指向内存块的指针进行更新
 * 因为 realloc 函数可能会使内存块移动到其他地方
 */
void allocation_with_realloc(int n) {
    char *a;
    a = malloc((n + 1) * sizeof(char));
    a = realloc(a, (n + 2) * sizeof(char));
}
