/*
 * @author Anger
 * @date 2022/8/29
 * @brief 将摄氏度转换成华氏度
 */
#include <stdio.h>
#define FREEZING_PT 32.0f
/*
 * 使用宏定义表达式
 * 表达式需要使用括号括起来
 * c 语言由一连串的记号组成
 * 即许多不在不改变意思的基础上无法分隔的字符组
 * 记号之间的空格数量没有要求
 * 但是无法把整个程序写在一行内
 * 因每条预处理的指令都需要单独一行
 */
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void) {
    float fahrenheit, celsius;

    printf("Enter fahrenheit temperature : ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREEZING_PT) / SCALE_FACTOR;

    printf("Celsius : %.2f", celsius);

    /*
     * 在 main 函数中
     * return 语句不是必须的
     * 如果没有return 语句
     * 程序一样会终止
     * 但是返回给操作系统的值是未定义的
     */
    return 0;
}
