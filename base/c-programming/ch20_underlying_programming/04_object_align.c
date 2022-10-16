/*
 * @author Anger
 * @date 2022/10/16
 * @brief 对象的对齐
 * 受硬件布线的影响或者为了提高存储期的访问效率
 * 要求特定对象类型在存储期里的位置只能开始于某些特定的字节地址
 * 这些字节地址都是某个数值 N 的特定倍数
 * 这称为对齐
 */
#include <stdio.h>
#include <stdalign.h>

/* 对齐操作符 */
void align_operator(void);
/* 对齐指定符 */
void align_specifier(void);

int main(void) {

    align_operator();

    align_specifier();

    return 0;
}

void align_operator(void) {
    printf("C11 特性，对齐运算符 _Alignof 获取指定类型的对齐值 %s\n", __FUNCTION__);
    printf("%zu, %zu, %zu, %zu\n",
           _Alignof(char),
           _Alignof(int),
           /* 如果应用于数组，则返回元素类型的对齐需求 */
           _Alignof(int [33]),
           _Alignof(struct {char c; double d;}));
}

void align_specifier(void) {
    printf("C11 在变量的声明中新增了对齐指定符，关键字 _Alignas %s\n", __FUNCTION__);
    /* 对齐声明符只能在声明或者复合字面量中使用
     * 强制被声明的变量按指定的要求对齐 */
    int _Alignas(8) foo;
}
