/*
 * 函数的实参
 * 函数的形参：出现在函数的定义中，以假的名字来表示函数调用时需要提供的值
 * 函数的实参：出现在函数调用中的表达式
 * 形参和实参差异不是很重要的时候，使用参数表示二者中的任意一个
 */
#include <stdio.h>

int power(int x, int p);

/**
 * 计算 x 的 p 次幂
 * @param x 原始数值
 * @param p 次幂
 * @return x ^ p
 *
 * c 语言中
 * 实参是值传递的
 * 调用函数时计算出每个实参表达式的值
 * 将其赋值给形参
 * 在函数执行的过程中
 * 形参的变化不会影响实参的值
 * 因为形参中包含的是实参的副本
 * 从效果上来说
 * 每个形参的行为好像是把变量初始化为与之相匹配的实参的值
 * 实参的值传递有利有弊
 * 因为形参的修改不会改变实参的值
 * 所以可以把形参当做函数的变量来使用
 * 可以减少真正需要的变量的数量
 */
int power(int x, int p) {
    int result = 1;
    /* 因为形参 p 不会改变实参的值
     * 可以对其在函数内进行修改
     * 可以减少变量的数量 */
    while (p-- > 0)
        result *= x;
    return result;
}

/**
 * 尝试将一个浮点数值分解成整数和小数部分
 * 因为函数无法返回两个数
 * 可以尝试把两个变量传递给函数
 * 分别在函数中修改为整数部分和小数部分
 * 但是下面这种做法其实是无效的
 * @param x 浮点数
 * @param int_part 整数部分变量
 * @param frac_part 小数部分变量
 * 因为函数参数是值传递的
 * 实参不会因为形参在函数内部的修改受到影响
 * 所以函数调用前后实参的值是不会发生变化的
 */
void decompose(double x, long int_part, double frac_part) {
    /*尝试将浮点数 x 分解成整数部分和小数部分*/
    int_part = (long) x;
    frac_part = x - (double)int_part;
    printf("decompose %f int part : %ld\n"
           "fraction part : %f\n",
           x, int_part, frac_part);
}

/* 测试对形参的修改不会影响实参的值 */
void test_ineffective_modify() {

    double x = 3.14, frac_part = 0;
    long int_part = 0;

    decompose(x, int_part, frac_part);

    printf("test decompose %f int part : %ld\n"
           "fraction part : %f\n",
           x, int_part, frac_part);
}

/**
 * 计算一个数的平方值
 */
int square(int n) {
    return n * n;
}

/* 测试实参类型转换 */
void test_argument_transform() {
    /*
     * 实参的类型与形参的类型可以不同
     * 管理实参的转换与编译器是否在调用前遇到函数的原型有关
     * 编译器在调用前遇到函数原型：
     * 就像使用赋值一样
     * 每个实参的值都被隐式转换为形参的类型
     * 编译器在调用前没有遇到原型
     * 编译器执行默认的参数提升
     * (1) 把 float 提升为 double
     * (2) 执行整值提升 把 char short 转为 int 类型
     * C99 实现整值提升
     */
    double d = 10;
    printf("square of %f : %d\n", d, square(d));
}

/**
 * 对数组中的元素求和
 * 数组类型实参
 * 当数组是一维数组时
 * 可以不说明数组的长度
 * 如果函数需要
 * 一般将数组的长度作为额外的参数提供
 * @param arr 数组
 * @param n 数组长度
 * @return 元素的和
 */
int sum_array(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += arr[i];
    return result;
}

void test_array_argument() {
    int n = 10;
    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    printf("sum of array : %d\n", sum_array(a, n));
}

/**
 * 如果将多维数组作为参数
 * 只能省略第一维的数组长度
 * @param a 多维数组
 * @param n 第一维数组长度
 * @return 求和结果
 */
int sum_multi_array(int a[][10][10], int n) {
    int result = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                result += a[i][j][k];
    return result;
}

void test_multi_dimensional_array_arg() {
    int i = 10, j = 10, k = 10;
    int a[i][j][k];
    for (int l = 0; l < i; ++l)
        for (int m = 0; m < j; ++m)
            for (int n = 0; n < k; ++n)
                a[l][m][n] = 1;

    printf("sum of multi dimensional array : %d\n", sum_multi_array(a, i));
}

/**
 * 将数组作为形参在函数中对形参数组中的元素进行修改
 * 会体现到数组实参中
 * @param a 数组形参
 * @param n 元素数量
 */
void modify_array_element(int a[], int n) {
    for (int i = 0; i < n; ++i)
        a[i]++;
}

void test_modify_array_element() {
    int a[5] = {};
    modify_array_element(a, 5);
    for (int i = 0; i < 5; ++i)
        printf("a[%d] = %d ", i, a[i]);
    puts("");
}

/*
 * 变长数组的函数原型可以和函数定义一样
 * 也可以以 * 取代数组形参中表示数组长度的形参名
 * 因为函数声明时，形参名是可选的
 * 如果第一个参数定义被省略了
 * 星号提供了一种线索-数组的长度与前面的参数有关
 */
int sum_variable_array(int n, int a[*]);

/**
 * C99 增加了变长数组的特性
 * 使用变长数组可以用非常量表达式指定数组的长度
 * 变长数组也可以作为参数
 * 第一个参数的值决定了第二个参数数组的长度
 * 两个形参的顺序不能颠倒
 * @param n 数组长度
 * @param a 变长数组
 * @return 数组中元素的和
 */
int sum_variable_array(int n, int a[n]) {
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += a[i];
    return result;
}

void test_variable_array() {
    int a[5] = {};
    printf("sum of a : %d\n", sum_variable_array(5, a));
}

/**
 * 使用变长多维数组作为参数
 * 变长数组的形参可以是任意的表达式
 * @param a 参数1
 * @param b 参数2
 * @param arr1 数组1
 * @param arr2 数组2
 * @return 多个数组中所有元素的和
 */
int sum_variable_multi_dimensional_array(int a, int b, int arr1[a][b], int arr2[a + b]) {
    int sum_arr2 = sum_variable_array((a + b), arr2);
    int sum_arr1 = 0;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            sum_arr1 += arr1[i][j];
    return sum_arr1 + sum_arr2;
}

void test_variable_multi_dimensional_arr() {
    int a = 10, b = 10;
    int arr1[a][b];
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            arr1[i][j] = 1;

    int arr2[a + b];
    for (int i = 0; i < a + b; ++i)
        arr2[i] = 1;

    printf("sum of arr1 & arr2 : %d\n",
           sum_variable_multi_dimensional_array(a, b, arr1, arr2));
}

/**
 * C99 允许在参数声明的时候使用 static 关键字
 * static 的不会对程序有任何影响
 * 它的存在只不过是一个提示
 * c 编译器可以依此生成更快的指令来访问数组
 * 如果参数是多维的数组 static 只能用于第一维
 * @param a
 * @return
 */
int sum_static_array(int a[static 3], int n) {
    int r = 0;
    for (int i = 0; i < n; ++i)
        r += a[i];
    return r;
}

void test_static_declare_parameter() {
    int n = 2;
    int a[n];
    for (int i = 0; i < n; ++i)
        a[i] = i;
    printf("sum of static arr : %d\n", sum_static_array(a, n));
}

/**
 * C99 复合字面量：通过指定数组包含的元素来创建没有名字的数组
 * 复合字面量的格式 ： (类型名) 初始化器
 */
void test_compound_literal() {

    /* 不指定数组长度，创建数组 */
    printf("sum array : %d\n", sum_array((int []){1, 2, 3, 4, 5}, 5));

    /* 显示声明数组长度，未初始化的元素的值为 0 */
    printf("sum array : %d\n", sum_array((int [10]){1, 2, 3, 4, 5}, 10));

    /* 复合字面量可以包含任意的表达式 */
    int n = 3;
    printf("sum array : %d\n", sum_array((int [2]){2 * n, n * n * n}, 2));
}

int main(void) {

    printf("%d to the power of %d : %d\n", 2, 3, power(2, 3));

    test_ineffective_modify();

    test_argument_transform();

    test_array_argument();

    test_multi_dimensional_array_arg();

    test_modify_array_element();

    test_variable_array();

    test_variable_multi_dimensional_arr();

    test_static_declare_parameter();

    test_compound_literal();

    return 0;
}