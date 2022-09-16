/*
 * @author Anger
 * @date 2022/9/16
 * @brief 字符串数组
 */
#include <stdio.h>

int main(void) {
    /* 使用二维数组存储字符串数组
     * 这种做法会导致数组参差不齐的长度的字符串都分配了最长字符串的空间
     * 导致空间浪费 */
    char numbers[][6] = {"one", "two", "three", "four", "five"};
    /* 大部分的字符串数组都是长短字符串混合
     * 可以通过建立一种特殊的数组来实现
     * 这个数组的元素都是指向字符串的指针 */
    char *six = "six";
    char *numbers_p[]  = {"one", "two", "three", "four", "five", six};
    for (int i = 0; i < 6; ++i)
        printf("%s ", numbers_p[i]);
    return 0;
}