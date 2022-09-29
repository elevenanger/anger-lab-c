/*
 * @author Anger
 * @date 2022/9/29
 * @brief 弹性数组
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * C99 弹性数组成员
 * 当结构的最后一个成员是数组时
 * 长度可以省略
 */
struct v_string {
    int len;
    char chars[];
};

int main(void) {
    int n = 10;
    struct v_string *str = malloc(sizeof(struct v_string) + n);
    str->len = n;

    return 0;
}