/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 获取输入的信息，根据信息进行计算
 */
#include <stdio.h>
/*
 * 程序含有常量时
 * 一般使用宏定义的特性给这些常量命名
 * 这里的 #define 是预处理器的指令
 * 在此行的结尾没有分号
 * 对程序进行预编译时
 * 预处理器会把宏替换为其表示的值
 */
#define INCHES_PER_POUND 166

int main() {
    int height = 0,
    length = 0,
    width = 0,
    volume = 0;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);

    volume = height * width * length;
    printf("Volume : %d \n", volume);

    printf("weight : %d", (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND);

    return 0;
}