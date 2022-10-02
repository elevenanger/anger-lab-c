/*
 * @author Anger
 * @date 2022/10/1
 * @brief 存储类型
 */
#include <stdio.h>

/* 变量的性质
 * 存储期
 * 作用域
 * 链接:
 * 实际上是指变量的名字的链接属性
 * 它确定了程序的不同部分可以通过变量名字共享此变量的范围
 * 具有外部链接的属性的名字，变量可以被程序的几个文件共享
 * 具有内部链接属性的名字，变量只能属于单独的一个文件，此文件中的函数可以共享此变量
 * 具有无链接属性的名字，变量单独属于一个函数，而且不能被共享
 * 在块内部声明的变量通常具有自动存储期，它的名字具有块作用域，并且无链接 */
void nature_of_variable(void);

/* auto 存储类型
 * 只对属于块的变量有效
 * auto 变量具有自动存储期
 * 它的名字具有块作用域
 * auto 类型不需要显式地声明
 * 因为对于块内部声明的变量是默认 auto 存储期的 */
void auto_type(void);

void static_type(void);

/* extern 存储类型使多个文件共享同一个变量
 * 变量在程序中可以有多次声明
 * 但是只能有一次定义
 * extern 变量始终具有静态存储期
 * 变量的作用域依赖于变量声明的位置
 * 声明在块内部具有块作用域
 * 否则具有文件作用域 */
void extern_storage_type(void);

/* 声明 register 类型要求编译器把变量存储在寄存器中
 * 声明变量的存储类型为 register 是一种请求，而不是命令
 * register 存储类型只对声明在块中的变量有效
 * register 变量具有和 auto 一样的存储期、名字、作用域和链接
 * 但是因为寄存器没有地址
 * 所以对 register 变量使用地址运算符 & 是非法的
 * register 存储类型最好用于需要频繁进行访问或者更新的变量 */
void register_storage_type(void);

/* 函数存储类型
 * 函数声明也可以包含存储类型
 * 但是选项只有 static 和 extern
 * 函数声明为 extern 说明函数具有外部链接属性，允许其它文件调用此函数
 * static 说明是内部链接
 * 只能在定义函数的文件内部调用此函数
 * 如果不指定函数的存储类型
 * 默认为具有外部链接
 * 声明函数是 static 是非常有用的
 * 1、更容易维护
 * 2、减少 名字空间污染 */
static void function_storage_type(void);

/*
 * 在程序最外层声明的变量具有静态存储期
 * 它的名字具有文件作用域和外部链接
 * 静态存储期
 * 文件作用域
 * 外部链接 */
int i;
/* 在块外部声明的 static 变量的名字具有内部链接
 * 在块外部声明的 static 变量只在声明它的文件内可见
 * 只有出现在同一个文件中的函数可以看到此变量 */
static int si;

int main(void) {

    auto_type();

    static_type();

    extern_storage_type();

    register_storage_type();

    function_storage_type();

    return 0;
}

void auto_type(void) {
    printf("auto type => %s\n", __FUNCTION__ );
    /* 块内部声明的变量
     * 默认 auto 存储期 */
    double d;
}

void static_type(void) {
    printf("static type => %s\n", __FUNCTION__ );
    /* 在块内部声明的变量存储期自动变成了静态的存储期
     * 块内声明的 static 变量在程序执行期间驻留在统一内存单元中
     * static 变量会无限期的保留值
     * 块内 static 变量具有以下特性 ：
     * 1、只有在程序执行前进行一次初始化
     * 2、每次函数递归调用时，如果函数有 static 变量，每次调用都会共享此变量
     * 3、虽然函数不返回具有 auto 存储期变量的指针，但是返回 static 变量的指针是可以的 */
    static double pi = 3.14;
}

void extern_storage_type(void) {
    printf("extern storage type => %s\n", __FUNCTION__ );
    extern int ei;
}

void register_storage_type(void) {
    printf("register storage type => %s\n", __FUNCTION__ );
    register int ri;
    for (ri = 0; ri < 100; ++ri)
        printf("%d ", ri);
    puts("");
}

static void function_storage_type(void) {
    printf("%s", __FUNCTION__ );
}
