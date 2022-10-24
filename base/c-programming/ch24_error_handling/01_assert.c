/*
 * @author Anger
 * @date 2022/10/24
 * @brief 断言
 */
#include <assert.h>
/* 只有定义了 NDEBUG 宏才进行断言检查 */
#ifdef NDEBUG
#include <assert.h>
#endif

/* assert 用法 */
void assert_usage(int i);

int main(void) {
    int i = 3;

    assert_usage(i);

    return 0;
}

void assert_usage(int i) {
    int a[10];
    /* C89 要求 assert 参数类型问 int
     * C99 允许参数为任意标量类型
     * assert(e) 的参数必须是 断言
     * 一个在正常情况下始终为真的表达式
     * 每次执行 assert 时
     * 都会检查参数的值
     * 如果参数的值不为 0
     * assert 什么都不做
     * 如果参数的值为 0
     * assert 会向 stderr 输出一条消息
     * 并且调用 abort 函数终止程序运行 */
    assert(i >= 1 && i < 10);
    a[i] = 0;
}
