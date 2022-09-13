/*
 * @author Anger
 * @date 2022/9/12
 * @brief 指针变量
 */
#include <stdio.h>

void declare_pointer_variable(void);

void address_of_operator(void);

void indirection_operator(void);

void pointer_assignment(void);

void pointer_argument(void);

void decompose(double x, long *int_part, double *frac_part);

void max_min(int a[], int n, int *max, int *min);

void test_max_min(void);

void return_pointer(void);

int main(void) {
    indirection_operator();
    pointer_assignment();
    pointer_argument();
    return_pointer();
    return 0;
}

/**
 * 声明指针变量
 */
void declare_pointer_variable(void) {
    /* 可执行程序由代码和数据（原始程序中的变量）构成
     * 程序中的每一个变量占一个或者多个字节
     * 把第一个字节的地址作为变量的地址
     * 虽然用数表示地址，但是地址的取值范围和整数的取值返回可能不同
     * 用特殊的指针变量来存储地址
     * 用指针变量 p 存储 i 的地址时 p 指向 i
     * 指针就是地址，指针变量就是存储地址的变量
     * 声明指针变量的形式和声明普通变量的形式基本一致
     * 唯一的不同之处就是在指针变量的变量名前面放置 * 号
     * 下述声明说明 p 是指向 int 类型对象的指针变量
     * 指针变量可以与其它变量一起出现在声明中
     * 每个指针变量只能指向一种特定类型(引用类型)的对象
     */
    int *p, i, arr[2], *q, **a;
}

/**
 * 取地址运算符 &
 * 为了找到变量的地址
 * 使用 & 运算符
 * 如果 x 是变量
 * &x 就是 x 的内存地址
 */
void address_of_operator(void) {
    /* 声明指针变量只是为指针留出空间，但是并没有把它指向对象
     * 在使用指针之前需要对指针进行初始化 */
    int *p;
    int i;
    /* 初始化指针变量的第一种方式
     * 使用 & 运算符将变量的地址赋给指针变量*/
    p = &i;
    /* 也可以在声明指针变量同时进行初始化
     * 但是变量 i 需要先进行声明 */
    int *q = &i;
    /* 可以合并声明变量、指针变量并进行赋值
     * 变量 需要先进行声明*/
    int j, *r = &j;
}

/**
 * 间接寻址运算符 *
 * 一旦指针指向了对象
 * 就可以使用间接寻址运算符 * 访问存储在对象中的内容
 * * 在不同的语境中的涵义不同
 * 在赋值语句中 *p 表示 p 的类型告诉编译器这是一个指针变量
 * 而在语句中出现时，* 号（作为一元运算符使用时）会执行间接寻址
 */
void indirection_operator(void) {
    int i = 10, *p = &i;
    /* p 指向 i，使用 *p 将取出 i 的值*/
    printf("i => %d\n", *p);
    /* 将 * 理解为 & 逆运算
     * 对变量使用取地址运算符 & 产生指向变量的指针
     * 对指针使用间接寻址运算符 * 则可以返回原始变量 */
    printf("i => %d\n", *&i);

    /* p 指向 i , *p 就是变量 i 的别名
     * *p 不仅仅拥有和 i 相同的值
     * 对 *p 的修改也会改变 i 的值*/
    *p = 11;
    printf("i => %d\n", i);
    printf("*p => %d\n", *p);
}

/**
 * 指针赋值
 */
void pointer_assignment(void) {
    puts("pointer assignment : ");
    int i, j, *p, *q;
    /* 把 i 的地址赋值给指针变量 p */
    p = &i;
    /* C 语言允许使用赋值运算符进行指针的复制
     * 前提是指针的类型相同
     * 把指针变量 p 的值复制给 q
     * p 和 q 指向相同的地方
     * 任意数量的指针都可以指向同一个对象*/
    q = p;

    *p = 1;
    printf("*p => %d\n", *p);
    printf("*q => %d\n", *q);
    printf("i => %d\n", i);

    *q = 2;
    printf("*p => %d\n", *p);
    printf("*q => %d\n", *q);
    printf("i => %d\n", i);

    j = 10;
    q = &j;
    printf("*q => %d\n", *q);
    /* *p = *q 是把 q 指向的变量 j 的值复制到
     * p 指向的变量 i 中*/
    *p = *q;
    printf("i => %d\n", i);
    printf("j => %d\n", j);
    *p = 20;
    printf("*p => %d\n", *p);
    printf("*q => %d\n", *q);
    printf("i => %d\n", i);
    printf("j => %d\n", j);
}

/**
 * 将指针变量作为函数的参数
 */
void pointer_argument(void) {
    double x = 10.23, frac, *frac_part_p = &frac;
    long int_part, *int_part_p = &int_part;
    decompose(x, int_part_p, frac_part_p);
    /* 因为 & 取地址运算符
     * 所以 decompose 的实参实际上是指向 int_part 和 frac 的指针
     * 而不是它们的值 */
    decompose(x, &int_part, &frac);
    printf("x => %g\t"
           "int_part => %ld\t"
           "frac_part => %g\n",
           x, int_part, frac);
    test_max_min();
}

/**
 * 将一个浮点型数值拆分为整数部分和小数部分
 * @param x 浮点型数值
 * @param int_part 指向保存整数部分变量的指针变量
 * @param frac_part 指向保存小数部分变量的指针变量
 */
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long) x;
    *frac_part = x - *int_part;
}

/**
 * 找出一个数组中的最大元素和最小元素
 * @param a 数组
 * @param n 数组的元素数量
 * @param max 最大元素
 * @param min 最小元素
 */
void max_min(int a[], int n, int *max, int *min) {
    int i;
    *max = *min = a[0];
    for (i = 0; i < n; ++i) {
        if (*max < a[i])
            *max = a[i];
        if (*min > a[i])
            *min = a[i];
    }
}

void test_max_min(void) {
    int n = 5, a[n], max, min;
    printf("\nEnter %d numbers : ", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    max_min(a, n, &max, &min);
    printf("\nmax number => %d\tmin number => %d\n", max, min);
}

/**
 * 使用 const 保护参数
 * const 来表明函数不会改变指针参数所指的对象
 * @param p 指针
 */
void f(const int *p) {
    if (*p > 10)
        printf("too big to ten");
    else if (*p < 10)
        printf("too small to ten");
    else
        printf("just to ten");
}

/**
 * 返回指向较大数字的指针
 */
int *max(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}

/**
 * 返回指针
 */
void return_pointer(void) {
    int a = 1, b = 2;
    int *p = max(&a, &b);

    printf("Bigger number => %d\n", *p);
}