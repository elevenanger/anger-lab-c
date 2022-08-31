/*
 * @author Anger
 * @date 2022/8/30
 * @brief 格式化输入
 */
#include <dtrace.h>

void test() {
    int i1, i2;
    float f1, f2;
    /*
     * 12 32 2.22 3.44
     * 12 32 2.220000 3.440000
     * scanf 是模式匹配的
     * 它会从左开始读取输入的信息
     * 直到读取到第一个匹配数据格式的内容
     * 再到第一个不匹配格式的数据
     * 如果 scanf 读取到不匹配的字符
     * 会把字符放回原处，以便后续的读取过程中再次读取
     * 这里的放回原处指的是在用户输入的过程中
     * 程序并没有读取输入
     * 数据会先放在一个缓冲区
     * 由 scanf 函数来读取
     * 如果模式匹配不上 scanf 函数把数据放回缓冲区后续再次读取
     */
    scanf("%d%d%f%f", &i1, &i2, &f1, &f2);
    printf("%d %d %f %f\n", i1, i2, f1, f2);

    /*
     * 2121/2323
     * scanf 会把 2121 与第一个 %d 相匹配
     * / 和 / 相匹配
     * 2323 与第二个 %d 相匹配
     */
    int i3, i4;
    scanf("%d/%d", &i3, &i4);
    // 如果需要格式化输出显示 % 字符，使用连续两个 %% 即可
    printf("%d %d %%\n", i3, i4);
}

int main(void) {

    test();

    return 0;
}