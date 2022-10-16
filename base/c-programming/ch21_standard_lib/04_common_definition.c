/*
 * @author Anger
 * @date 2022/10/16
 * @brief 常用定义
 */
#include <stdio.h>
#include <stddef.h>

void offset_of(void);

struct s {
    int a;
    float f;
    double d;
    char c[20];
    unsigned int ui;
};

int main(void) {
    offset_of();
    return 0;
}

void offset_of(void) {
    printf("常用的宏定义 offsetof(struct s, e)\n"
           "用来计算 s 结构的起点到指定成员之间的字节数\n");
    printf("offsetof(struct s, ui) = %ld\n", offsetof(struct s, ui));
}
