/*
 * @author Anger
 * @date 2022/9/20
 * @brief 预处理器工作原理
 *
 * #include 指令告诉预处理器打开一个特定的文件
 * 将它的内容作为正在编译的文件的一部分包括进来
 */
#include <stdio.h>
/* #define 指令定义了一个宏
 * 用它来代表某样东西的一个名字
 * 例如常量或者表达式
 * 预处理器会通过将宏的名字和它的定义存储在一起来响应 #define 指令
 * 当这个宏在后面的程序中使用时
 * 预处理器将将替换为其定义的内容 */
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void) {
    float fahrenheit, celsius;

    printf("Enter Fahrenheit temperature : ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;

    printf("celsius equivalent is : %.1f\n", celsius);
    return 0;
}