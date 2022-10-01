/*
 * @author Anger
 * @date 2022/10/1
 * @brief 声明的语法
 */
#include <stdio.h>

void declare_variable(void);

/**
 * 函数声明
 * 表示该函数有一个实参为 float 类型
 * 返回值也是 float 类型
 * @param f float 类型参数
 * @return float 类型返回值
 *
 * 声明的形式
 * 声明指定符 声明符
 * 声明指定符 描述声明的变量或者函数的性质
 * 声明符 给出了它们的名字，并且可以提供关于性质的额外的信息
 */
float declare_function(float f);

/* 声明指定符包括以下三类
 * 1、存储类型符
 * 2、类型限定符
 * 3、类型指定符 */
void declaration_specifier(void);

/* 存储类型符包括：
 * auto static extern register */
void storage_type(void);

/* 类型限定符包括：
 * const volatile
 * c99 新增 restrict */
void type_qualifier(void);

/* 类型指定符包括 :
 * void char short int long float double signed unsigned
 * 也包括结构、联合和枚举
 * union struct enum
 * typedef 创建的类型名也是类型指定符 */
void type_specifier(void);

int main(void) {
    declare_variable();
    declaration_specifier();
    return 0;
}

/**
 * 声明为编译器提供有关标识符涵义的信息
 * 声明变量
 */
void declare_variable(void) {
    printf("声明变量 => %s\n", __FUNCTION__ );
    /*
     * 这个声明表示
     * 名字 i 在当前作用域内是一个数据类型为 int 的变量
     */
    int i;
}

/**
 * 声明指定符
 */
void declaration_specifier(void) {
    printf("声明指定符 => %s\n", __FUNCTION__ );
    storage_type();
    type_qualifier();
    type_specifier();
}

void storage_type(void) {
    printf("存储类型符 => %s\n", __FUNCTION__ );
    auto int i;
    static int j;
    extern int k;
    register int l;
}

/*
 * 类型限定符
 */
void type_qualifier(void) {
    printf("类型限定符 => %s\n", __FUNCTION__ );
    const int i;
    volatile int j;
    int* restrict k;
}

void type_specifier(void) {
    printf("类型指定符 => %s\n", __FUNCTION__ );
    void *p;
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    signed int si;
    unsigned int ui;

    union u {
        int i;
        float f;
    };

    struct s {
        int i;
        double d;
    };

    typedef enum {MALE, FEMALE} sex;
}