/*
 * 释放存储空间
 */
#include <stdlib.h>

void memory_leak(void);
void free_memory_space(void);
void dangling_pointer(void);

int main(void) {
    return 0;
}

/**
 * 释放内存空间
 */
void memory_leak(void) {
    int *p, *q;
    p = malloc(100);
    q = malloc(200);
    /* 之前为指针 p 和 q 都分配了内存空间
     * 将 p 指向 q 之后
     * 原本为 p 分配的内存空间将不会再被访问
     * malloc 等函数分配的内存空间都来自堆中
     * 如果频繁分配内存最终会导致内存耗尽
     * 对于程序而言，不能再访问到的内存块被称为垃圾
     * 留有垃圾的程序存在内存泄露的风险
     * 需要使用 free 函数来释放内存空间 */
    p = q;
}

/**
 * 使用 free 函数释放内存空间
 * free 函数的实参必须是之前由内存分配函数返回的指针
 * 如果参数指向别的对象
 * 可能会产生未定义的行为
 */
void free_memory_space(void) {
    int *p, *q;
    p = malloc(100);
    q = malloc(200);
    free(p);
    p = q;
}

/**
 * 悬空指针问题
 * free 函数会释放指针指向的内存块
 * 但是不会改变指针本身
 * 试图继续使用指针访问或者修改指针指向的内存将会造成严重的后果
 */
void dangling_pointer(void) {
    int *p, *q = malloc(100);
    p = q;
    /* 此时 p 和 q 都指向同一个内存块
     * 如果释放了其中一个指针指向的内存块
     * 会导致两个指针都悬空
     * 在复杂程序中，这是极难发现的问题 */
    free(q);
}
