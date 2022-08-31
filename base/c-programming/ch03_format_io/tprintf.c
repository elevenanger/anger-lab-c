/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 使用 printf 格式化输出
 */
#include <stdio.h>

int main(void) {
    int i;
    float x, y;

    i = 40;
    x = 898.23f;
    y = 890389.43f;

    /*
     * 格式化字符串包含铺铜字符和转换说明
     * 转换说明以 % 开头
     * 用来表示打印的过程中待填充的占位符
     * 转换说明后面的信息指定了把数值从内部形式转换成打印形式的方法
     * 转换的信息包括最小的字段宽度 准换数据的格式和转换的精度
     * %5d 将以 |   40| 的形式转换 40 转换格式默认是左对齐
     * 前面加上负号则变为右对齐
     * e 表示指数形式的浮点数
     * g 表示指数形式或者十进制形式的浮点数
     * 形式的选择根据数值的大小决定
     */
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
    printf("%g", y);
}