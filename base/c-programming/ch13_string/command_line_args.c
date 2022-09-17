/*
 * @author Anger
 * @date 2022/9/17
 * @brief 命令行参数
 */
#include <stdio.h>

/**
 * c 程序也可以接收命令行参数
 * @param argc 参数计数，命令行参数的数量
 * @param argv 参数向量，指向命令行参数的指针数组，这些命令行的参数以字符串的形式存储
 * argv[0] 指向程序名
 * arg[1] 到 argv[argc - 1] 指向剩余的命令行参数
 * argv[argc] 是一个附件元素，这个元素始终是一个空指针
 * 空指针是不指向任何地方的特殊指针
 * 宏 NULL 代表空指针
 */
int main(int argc, char *argv[]) {

    /* 使用数组下标访问命令行参数 */
    for (int i = 1; i < argc; ++i)
        printf("arg %d => %s\n", i, argv[i]);

    /* 构造一个指向 arg[1] 的指针，然后进行指针自增操作来逐个访问数组剩余元素
     * 数组最后一个元素为空指针
     * 所以在循环找到空指针即可停止 */
    for (char **p = &argv[1]; *p != NULL; p++)
        printf("arg => %s\n", *p);

    return 0;
}