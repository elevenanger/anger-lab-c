/*
 * @author Anger
 * @date 2022/9/27
 * @brief 动态存储分配
 * 在程序执行期间分配存储空间的能力
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100

void memory_allocation_function(void);
void dynamic_memory_allocation(void);
char *concat(char *s1, char *s2);

int main(void) {
    dynamic_memory_allocation();

    char *s;
    s = concat("abcd", "efg");
    printf("concatenated str => %s\n", s);
    /* 当动态分配的内存不需要再使用的时候
     * 使用 free 函数释放它占用的空间 */
    free(s);

    return 0;
}

/**
 * 内存分配函数
 * 为申请内存块而调用内存分配函数时
 * 因为函数无法知道计划存储在内存块中的数据是什么类型的
 * 所以它不能返回具体的类型
 * 函数会返回 void* 类型的值
 * void * 类型是通用指针
 * 本质上是内存地址
 */
void memory_allocation_function(void) {
    /* malloc 分配内存块，但是不对内存块进行初始化 */
    void *p = malloc(100);
    /* calloc() 分配内存块，并且将内存块进行清零 */
    p = calloc(100, 1000);
    /* 调整之前分配的内存块大小 */
    realloc(p, 2000);
    /* 调用内存分配函数时
     * 找不到满足需要大小的内存块
     * 如果发生了这样的问题
     * 函数会返回空指针
     * 空指针是不指向任何地方的指针
     * 在把函数返回值存储到指针变量之后
     * 需要判断指针变量是否为空指针
     * 空指针使用 NULL 宏来表示
     * 以下两种方式都可以用于测试空指针 */
    if (p == NULL)
        printf("null pointer !\n");
    if (!p)
        printf("null pointer !\n");
}

/**
 * 动态分配内存空间
 */
void dynamic_memory_allocation(void) {
    /* malloc 分配 STR_LEN + 1 大小的内存块
     * 返回指向该内存块的指针
     * 字符串是 char * 类型
     * 执行赋值操作时将通用指针转换为 char* 类型
     * 通过这种方式可以在程序运行时动态分配内存空间 */
    char *s = (char *) malloc(STR_LEN + 1);
    strcpy(s, "this is dynamic malloc memory space.");
    printf("%s => %s\n", __FUNCTION__, s);
}

/**
 * 拼接字符串
 * @param s1 第一个字符串
 * @param s2 第二个字符串
 * @return 拼接后的字符串
 */
char *concat(char *s1, char *s2) {
    char *concatenated_str;
    /* 初始化内存块的大小为待拼接的字符串长度之和 + 1
     * 因为 malloc 是返回的是通用类型指针
     * 所以不需要显式地进行类型转换 */
    concatenated_str = malloc(strlen(s1) + strlen(s2) + 1);
    strcat(concatenated_str, s1);
    strcat(concatenated_str, s2);
    return concatenated_str;
}
