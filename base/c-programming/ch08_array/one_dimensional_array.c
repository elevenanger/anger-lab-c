/*
 * @author Anger
 * @date 2022/9/4
 * @brief 一维数组
 * 数组是包含多个数据值的数据结构
 * 每个数据具有相同的类型，这些数据值被称为元素
 * 最简单的数组是一维数组
 * 一维数组中的元素一个接一个排列在单独一行内
 */
#include <stdio.h>
#include <stdbool.h>
#define ARR_NUMBER 3
#define SIZE(a) (int) sizeof(a) / sizeof(a[0])

void declare_array() {
    /*
     * 声明数组中元素类型为 int
     * 元素的数量为 10
     * 数组元素可以是任意类型
     * 长度可以是任何整数常量表达式
     */
    int a[10];
    /* 因为程序的改变可能需要调整数组的长度，所以比较好的方式是用宏来定义数组的长度 */
    int arr[ARR_NUMBER];
}

/**
 * 数组下标
 * 用于存取特定的数组元素
 * 数组元素始终从 0 开始
 */
void array_index() {
    int a[ARR_NUMBER];
    /* 往数组中指定下标写入数据 */
    for (int i = 0; i < ARR_NUMBER; i++)
        a[i] = i;

    /* 读取数组中指定下标的数据 */
    for (int i = 0; i < ARR_NUMBER; i++)
        printf("%d ", a[i]);

    puts("");
}

/**
 * 数组可以指定初始化长度进行初始化
 * 最常见的初始化方式是使用大括号括起来的常量表达式列表
 * 常量表达式之间使用逗号分隔
 * 如果初始化的数组长度小于指定的初始化长度
 * 数组中剩余的元素会被赋值为 0
 * 也可以不指定数组长度进行数组初始化
 * 如果指定了初始化式
 * 可以省略数组的长度
 */
void array_initialize() {
    /* 指定数组长度进行初始化，数组元素少于声明的数字会初始化为0 */
    int a[ARR_NUMBER] = {1, 2};
    for (int i = 0; i < ARR_NUMBER; i++)
        printf("%d ", a[i]);

    puts("");

    /*
     * 指定初始化式
     * 可以省略数组的长度
     */
    int b[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
        printf("%d ", b[i]);

    puts("");

    /*
     * 数组中只有少量元素需要进行初始化的情况
     * C99 可以指定初始化式
     * 对于指定元素进行赋值
     * [2】 = 10
     * 括号中的数字 2 称为指示符
     * 如果指定了数组长度 n
     * 指示符的值只能为 0 ~ n 之间的整数
     */
    int c[10] = {[2] = 10, [5] = 20, [8] = 30};
    for (int i = 0; i < 10; ++i)
        printf("c[%d] %d\n", i, c[i]);

    puts("");

    /*
     * 使用初始化式还有一个好处就是赋值的顺序不是问题
     * 如果没有指定数组的长度
     * 指示符可以是任何非负整数
     * 编译器将会根据最大的指示符来推断出数组的长度
     */
    int d[] = {[3] = 100, [10] = 2, [8] = 5, [20] = 20};
    for (int i = 0; i < 21; ++i)
        printf("d[%d] %d\n", i, d[i]);
    puts("");

    /*
     * 可以混合使用新旧方式初始化数组
     * 这个初始化式中数组的钱三个元素为 1 2 3
     * 第 5 个元素的值为 10
     * 6 7 个元素的值为 8 9
     * 一共有 7 个元素
     * 没有指定的元素都赋值为 0
     */
    int e[] = {1, 2, 3, [5] = 10, 8, 9};
    for (int i = 0; i < 8; ++i)
        printf("e[%d] %d\n", i, e[i]);
}

void reverse() {

    int a[ARR_NUMBER];

    printf("Enter %d number : ", ARR_NUMBER);

    for (int i = 0; i < ARR_NUMBER; i++)
        scanf("%d", &a[i]);

    for (int i = ARR_NUMBER - 1; i >= 0; i--)
        printf("%d ", a[i]);
}

/**
 * 输入一个数字
 * 查找其中是否存在重复的数字
 */
void repeat_element() {
    /* 初始化一个 bool 值类型的数组，所有的值都设置为 false */
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number : ");
    scanf("%ld", &n);

    /*
     * 输入的数字每一位对 10 进行取模
     * 将数组中取模的结果位设置为 true
     * 如果取模结果位为 true
     * 说明存在重复的数字
     * 结束循环
     */
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) break;
        digit_seen[digit] = true;
        n /= 10;
    }

    /*
     * 如果 n > 0 说明循环的过程中结束了循环
     * 存在重复数字
     * 如果取模的操作一直持续到数字变为 0
     * 说明不存在重复的数字
     */
    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeat digit\n");
}

/**
 * 对数组使用 sizeof() 运算符
 * 运算符 sizeof() 可以确定数组的大小
 * 数组 int a[10]
 * 那么 sizeof(a) 为 40
 * 也可以使用 sizeof 计算数组元素的大小
 * 使用 数组大小 / 元素大小 可以得到数组的长度
 */
void sizeof_array() {
    int a[10] = {};
    printf("sizeof(a) 数组的长度 : %d\n", sizeof(a));

    /*
     * 使用数组的大小除以单个元素的大小
     * 来确定数组的长度
     * 然后循环对数组中的每个元素进行赋值
     * 使用这种方法，如果以后数组的长度变化也不需要修改循环代码
     * sizeof() 运算符得到的是一个 size_t 类型的元素
     * 一般使用 int 类型对值进行转换
     * 但是这个写法比较冗长
     * 可以定义一个宏来实现会比较方便
     * #define SIZE(a) (int) sizeof(a) / sizeof(a[0])
     *
     */
    for (int i = 0; i < (int) (sizeof(a) / sizeof(a[0])); ++i)
        a[i] = 1;

    for (int i = 0; i < SIZE(a); ++i)
        printf("%d ", a[i]);

    puts("");
}

void calculate_interest() {

    int interest, year, initial_value = 100;
    double values[5];

    printf("Enter interest rate : ");
    scanf("%d", &interest);
    puts("");

    printf("Enter number of years : ");
    scanf("%d", &year);
    puts("");

    for (int i = 0; i < SIZE(values); ++i)
        values[i] = initial_value;

    printf("\nYears   ");
    for (int i = 0; i < SIZE(values); ++i)
        printf("%5d%%  ", interest + i);
    puts("");

    for (int i = 1; i <= year ; ++i) {
        printf("%3d     ", i);
        for (int j = 0; j < SIZE(values); ++j) {
            values[j] += (double)(interest + j) / 100 * values[j];
            printf("%7.2f ", values[j]);
        }
        puts("");
    }
    puts("");
}

int main(void) {

    array_index();

    array_initialize();

    sizeof_array();

    calculate_interest();

    repeat_element();

    reverse();

    return 0;
}