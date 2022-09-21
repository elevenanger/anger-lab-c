/*
 * @author Anger
 * @date 2022/9/20
 * @brief 宏定义
 * 宏定义的作用范围通常到出现这个宏的结尾
 * 宏不能被定义两遍，除非新的定义和旧的定义是一样的
 */
#include <stdio.h>

/* 简单宏定义（对象式宏）
 * #define 标识符 替换列表
 * 宏的替换列表可以包括
 * 标识符、关键字、数值常量、字面常量、字面串、运算符和标点符号
 * 使用宏的优点 ：
 * 1、程序更加易读
 * 2、程序易于修改，修改一个宏定义就可以修改程序中出现这个宏的地方
 * 3、避免前后不一致的键盘输入错误
 * 4、对于 c 语言语法进行最小修改
 * 5、对类型的重命名
 * 6、控制条件编译 */
#define NUM             100
#define TRUE            1
#define FALSE           0
#define PI              3.14
#define CR              '\r'
#define EOS             '\0'
#define MEM_ERR         "error not enough memory"
/* 带参数的宏（函数式宏）
 * #define 标识符(x1, x2, ... , xn) 替换列表
 * 函数式宏的有点：
 * 1、程序可能会稍微快一些
 * 2、更通用，与函数的参数不同，宏的参数没有类型
 * 缺点：
 * 1、编译后的代码会变大
 * 2、宏参数没有类型检查（是优点也是缺点）
 * 3、无法使用指针指向宏
 * 4、宏可能不止一次地计算它的参数（带副作用的参数会在替换的过程中多次进行计算，
 * 尽量避免宏定义中使用带副作用的参数）
 * */
#define SIZE(a)         (int) (sizeof(a) / sizeof(a[0]))
#define MAX(x, y)       ((x) > (y) ? (x) : (y))
#define IS_EVEN(n)      ((n) % 2 == 0)
/* # 运算符将宏的一个参数转换为字面串
 * 它仅允许出现在带参数的宏的替换列表中 */
#define PRINT_INT(n)    printf(#n " => %d\n", n)
/* ## 将两个运算符粘合在一起，成为一个记号
 * 粘合 会在形参被相应的实际参数替换后发生 */
#define MK_ID(n)        i##n
#define GENERIC_MAX(type)           \
type type##_max(type x, type y) {   \
    return x > y ? x : y;           \
}                                   \

/* 将会被替换为 float float_max(float x, float y)*/
GENERIC_MAX(float)

/* 宏的替换列表可以包含对其它宏的调用
 * 如果宏定义的替换列表中有运算符
 * 那么始终要将替换列表添加到括号里面
 * 如果宏有参数，每个参数每次在替换列表中出现时都需要放在圆括号中 */
#define TWO_PI (PI * 2)
/* 使用 #undef 取消定义一个宏 */
#undef  CR

void pre_defined_macro(void);
void empty_macro_arg(void);
void var_arg_macro(void);
void func_identifier(void);

int main(void) {

    int x = 100, y = 101;
    printf("max(x, y) => %d\n", MAX(x, y));
    printf("NUM is even => %d\n", IS_EVEN(NUM));
    printf("%s\n", MEM_ERR);
    printf("TRUE => %d\n", TRUE);
    printf("FALSE => %d\n", FALSE);
    printf("PI => %g\n", PI);
    printf("TWO_PI => %g\n", TWO_PI);

    /* 副作用运算执行了两次 */
    MAX(x++, y++);
    printf("x => %d y=> %d\n", x, y);

    PRINT_INT(x);
    /* PRINT_INT(x + y) 经过替换变成：
     * printf("x + y" " => %d\n", n)
     * 因为相邻的两个字面串会被合并
     * 所以等价于
     * printf("x + y => %d\n", n)*/
    PRINT_INT(x + y);

    /* i##n 将会被替换为 i1 i2*/
    int MK_ID(1) = 10, MK_ID(2) = 11;
    printf("i1 => %d  i2 => %d\n", i1, i2);

    printf("max float number => %g\n", float_max(10.2f, 20.3f));

    pre_defined_macro();
    empty_macro_arg();
    func_identifier();

    return 0;
}

/**
 * 预定义宏
 * C 语言中有一些预定义宏
 * 每个宏表示一个整型常量或者字面串
 */
void pre_defined_macro(void) {
    /* __FILE_NAME__ 文件名 */
    printf("Anger Lab C %s \n", __FILE_NAME__);
    /* __DATE__ 编译日期 __TIME__ 编译时间 */
    printf("Compiled on %s at %s. \n", __DATE__, __TIME__);
    /* __FILE__ 和 __LINE__ 可以帮助很快找到错误 */
    printf("file %s line no is => %d \n", __FILE__, __LINE__);
}

/**
 * C99 允许空的宏调用中的所有或者任意参数为空
 * 这样的调用和一般调用一样需要有一样多的逗号
 */
void empty_macro_arg(void) {

#define ADD(a, b) (a + b)
    int i = 10, j = 5;
    printf("i + j => %d\n", ADD(i, j));
    /* 宏定义的参数允许为空，这个表达式等价于 10 + i */
    printf("10 + i => %d\n", 10 + ADD(,i));

#define MK_STR(x) #x
    /* 如果 # 或者 ## 运算符的操作数为空时，将会被替换成空字符串 */
    printf("make string => %s\n", MK_STR());
    char empty_str[] = MK_STR();

#define JOIN(a, b, c) a##b##c
}

/**
 * 可变参数宏
 * 在 C99 中允许宏具有可变长度的参数列表
 */
void var_arg_macro(void) {
#define TEST(condition, ...) ((condition) ? \
printf("Passed test : %s\n", #condition) :  \
printf(__VAR_ARGS__))
}

/**
 * __func__ 标识符
 * C99 特性
 * 每一个函数都可以访问 __func__ 标识符
 * 它的行为类似一个存储当前正在执行的函数的名字的字符串变量
 */
void func_identifier(void) {
#define FUNCTION_CALLED() printf("%s called\n", __func__)
#define FUNCTION_RETURNS() printf("%s returns\n", __func__)
    FUNCTION_CALLED();
    puts("Do Nothing...");
    FUNCTION_RETURNS();
}