/*
 * @author Anger
 * @date 2022/9/15
 * @brief 字符串变量
 */
#include <stdio.h>
#define STR_LEN 8

void string_variable_initialization(void);
void char_array_and_char_pointer(void);

int main(void) {
    return 0;
}

/**
 * 初始化字符串变量
 */
void string_variable_initialization(void) {
    /* 在声明时进行初始化
     * 声明用来存放字符串的字符数组通常比需要存放的字符数量多一位用于存放空字符 */
    char s1[STR_LEN + 1] = "Sep 15";
    /* "Sep 15" 是字面串的初始化器，也可以写成初始化字符数组的形式
     * 如果初始化器太短不能填满字符串变量编译器会添加空字符串
     * 如果指定的字符数组的长度小于字符串的长度
     * 编译器会忽略空字符
     * 使得数组无法作为字符串使用
     * */
    char s2[STR_LEN + 1] = {'S', 'e', 'p', ' ', '1', '5', '\0'};
    /* 声明字符串的时候可以省略字符数组长度,编译器会自动计算字符串的长度 */
    char s3[] = "Sep 15";
}

/**
 * 字符数组与字符指针
 */
void char_array_and_char_pointer(void) {
    /* 字符数组
     * 声明为数组时
     * 与任意的数组元素一样
     * 可以修改存储在 date1 中的字符
     * 声明为数组是 date1 是数组名 */
    char date1[] = "Sep 15";
    /* 字符指针
     * 声明为指针时
     * date2 指向字面串
     * 字面串是不可修改的
     * 声明为指针时 date2 是变量名
     * 这个变量可以在运行时指向其它的字符串
     * 指针变量为指针分配空间
     * 但是不会为字符数组分配空间
     * 使用字符指针作为字符串之前必须先把它指向字符数组 */
    char *date2 = "Sep 15";
}
