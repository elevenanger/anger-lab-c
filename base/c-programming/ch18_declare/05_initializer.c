/*
 * @author Anger
 * @date 2022/10/12
 * @brief 初始化器
 * c 语言可以在声明变量的时候为它们指定初始值
 */
#include <stdio.h>
#define FIRST 1
#define LAST 100
#define FIRST_LOWER_CHAR 'a'
#define PRINT_FUNC printf("\n%s\n", __FUNCTION__ )

typedef struct {
    char *name;
    int age;
} person;

person wong = {"wang wu", 40};

void simple_initializer(void);

void other_initializer(int n);

void uninitialized_variable(void);

int main(void) {

    simple_initializer();

    other_initializer(LAST);

    uninitialized_variable();

    return 0;
}


void simple_initializer(void) {
    PRINT_FUNC;

    int i = 10 / 3;
    printf("简答的变量初始化器，就是一个与变量类型相同的表达式:\n"
           "i = 10 / 3 => %d\n", i);

    int *p = &i;
    printf("指针变量的初始化器必须是具有和变量类型相同类型或者 void* 类型指针表达式:\n"
           "int *p = &i => %d\n", *p);

    char str[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', '\0'};
    printf("数组、结构或者联合的初始化器通常是带有花括号的一串值:"
           "char str[10] => %s\n", str);
}

/**
 * 初始化器其它的形式
 */
void other_initializer(int n) {
    PRINT_FUNC;

    static int i = LAST - FIRST;
    printf("C99 具有静态存储期变量的初始化器必须是常量:\n"
           "static int i = LAST - FIRST => %d\n", i);

    int j = n * 10;
    printf("如果变量具有自动存储期，那么它的初始化器不必是常量:\n"
           "int j = n * 10 => %d", j);

    char str[5] = {FIRST_LOWER_CHAR, FIRST_LOWER_CHAR + 1,
                   FIRST_LOWER_CHAR + 2, FIRST_LOWER_CHAR + 3, '\0'};
    printf("包含花括号的数组、结构或联合的初始化器必须只包含常量表达式，不允许有变量或者函数调用:\n"
           "char str[5] => %s", str);

    person old_wong = wong;
    printf("具有自动类型的结构或者联合的初始化器可以是另外一个结构或者联合:\n"
           "person old_wong = wong\n"
           "old_wong.name => %s\n"
           "old_wong.age => %d\n", old_wong.name, old_wong.age);
}

void uninitialized_variable(void) {
    PRINT_FUNC;

    int i;
    static int j;
    static double d;
    static float *f;
    printf("变量的初始化值依赖于变量的存储期\n"
           "具有自动存储期的变量没有默认的初始值\n"
           "具有静态存储期的变量默认情况下值为0\n"
           "指针初始化为空指针\n");
    printf("static int j => %d\n", j);
    printf("static double d => %g\n", d);
}
