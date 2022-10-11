/*
 * @author Anger
 * @date 2022/10/11
 * @brief 声明符
 * 声明符包含标识符（声明的变量或者函数的名字）
 * 标识符的前面可能有 * 号
 * 后面可能有 () []
 * 通过将这些符号组合在一起可以创建复杂的声明符
 */
#include <stdio.h>
#include <stdlib.h>

 /**
 * 简单声明
 * simple_declaration(void)
 * 用 () 结尾的声明符表示函数
  * @param pf 函数指针
  */
void simple_declaration(double (*pf) (int i));

double area_of_circle(int radius);

void complex_declaration(int *(*x[10])(int));

int *decuple(int i);

int main(void) {


    simple_declaration(area_of_circle);

    /*
     * 使用类型定义来简化声明
     * fcn 是实参为 int 类型，返回 int 类型指针的函数
     */
    typedef int *fcn(int);
    /* fcn_ptr 是指向 fcn 类型的指针 */
    typedef fcn *fcn_ptr;
    /* fcn_ptr_arr[10] 是长度为 10 的 fcn_ptr 类型数组 */
    typedef fcn_ptr fcn_ptr_arr[10];
    /* function_arr 具有 fcn_ptr_arr 类型 */
    fcn_ptr_arr function_arr;

    for (int i = 0; i < 10; ++i)
        function_arr[i] = decuple;

    complex_declaration(function_arr);

    return 0;
}

/**
 * 简单的声明
 */
void simple_declaration(double (*pf) (int i)) {
    printf("简单声明 => %s\n", __FUNCTION__ );
    /* 声明名为 i 的 int 类型变量 */
    int i = 3;
    /* 用 * 开头的声明符表示指针 */
    char *p;
    /* 用 [] 结尾的声明符表示数组 */
    char arr[10];

    double area = pf(3);
    printf("%d radius area => %g\n", i, area);
}

double area_of_circle(int radius) {
    return 3.14 * radius * radius;
}

/**
 * 解释复杂的声明
 * 1、始终从内往外读声明符：定位生命标识符，从此处开始解释声明
 * 2、始终使 [] () 优先于 *
 * int *(*x[10])(void) 解释：
 * 1、x 后面跟着 [10] [] 的优先级高于 * 表示 x 是一个长度为 10 的数组
 * 2、从左侧找到数组元素的类型为 * 指针
 * 3、从右侧找到指针指向的数据类型 (int)（int 类型实参的函数）
 * 4、左侧看函数的返回内容 int* (指向 int 类型的指针)
 * @param x
 */
void complex_declaration(int *(*x[10])(int)) {
    for (int i = 0; i < 10; ++i)
        printf("x[%d] => %d\n", i, *x[i](i));
}

int *decuple(int i) {
    int *p = malloc(sizeof(int));
    *p = i * 10;
    return p;
}
