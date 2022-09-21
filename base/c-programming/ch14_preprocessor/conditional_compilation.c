/*
 * @author Anger
 * @date 2022/9/21
 * @brief 条件编译
 */
#include <stdio.h>

#define DEBUG 1
#define DEBUG_MODE

void if_and_endif(void);
void defined_operator(void);

int main(void) {
    if_and_endif();
    defined_operator();
    return 0;
}

void if_and_endif(void) {
    /* if 指令测试 DEBUG 的值
     * 如果值不为 0 则执行后面的代码
     * 如果值为 0 则将后面的表达式删除
     * 直到遇到 #endif 结束*/
#if DEBUG
    printf("function => %s Debug mode.\n", __func__);
#endif
    printf("function => %s normal message.\n", __func__);
}

/**
 * defined(macro) 运算符一般与 #if 运算符一起使用
 * 仅当 DEBUG_MODE 定义成宏时 #if 和 #endif 代码才保存在程序中
 * 它只检查一个宏有没有被定义
 * 所以宏无需进行赋值
 */
void defined_operator(void) {
#if defined(DEBUG_MODE)
    printf("function => %s debug mode\n", __func__);
#endif
    printf("function => %s normal message\n", __func__);
}
