/*
 * @author Anger
 * @date 2022/8/30
 * @brief 赋值运算符
 */
#include <stdio.h>

/**
 * 简单赋值
 * 表达式 v = e
 * 表示计算出 e 表达式的值
 * 将其赋值给 v
 * e 可以是常量、变量或者更加复杂的表达式
 * 如果 v 和 e 的类型不同
 * 赋值运算会把 e 的类型转换成 v 的类型
 */
void simple_assignment() {
    int h, i, j, k;
    float f = 2.3f;
    i = 5; /* 常量 */
    j = i; /* 变量 */
    k = - i * 10 / j; /* 表达式 */
    h = j / f;
    printf("h = %d i = %d j = %d k = %d\n", h, i, j, k);
    /*
     * 在许多编程语言中
     * 赋值是语句
     * 但是 c 语言中
     * 赋值是操作符
     * 赋值操作产生结果
     * v = e 的值就是赋值运算后 v 的值
     * 副作用：
     * 通常我们不希望运算符修改它的操作数
     * i + j 不会改变 i 或者 j 的值，只是计算出它们相加的结果
     * 大多数 c 语言的运算符不会改变操作数的值
     * 但是也有一些会改变，这类运算符所做的不只只是计算出值
     * 这些运算符是存在副作用的
     * 简单赋值运算符 = 是一个有副作用的操作符
     * 因为它会改变左操作数
     * 对表达式 i = 10 求值产生的结果为 10
     * 并把 10 赋值给了操作数 i
     * 因为赋值是运算符，所以可以把多个赋值语句连在一起 i = j = 10
     * 运算符 = 是右结合的
     * 所以上述表达式等价于 i = (j = 10)
     * 大多数的 c语言允许它们的操作数是变量、常量常量或者其它运算符的表达式
     * 然而赋值运算符要求它的左表达式必须是左值
     * 左值表示存储在计算机内存中的对象
     * 而不是常量或者计算的结果
     */
    i = 1 + (j = 10);
    printf("i = %d j = %d\n",i, j);
}

/**
 * 复合赋值
 * 利用变量原来的值经过计算出新的值重新赋值给该变量
 */
void compound_assignment() {
    int i, j;
    i = 100;
    j = 100;
    /*
     * v += e 不等价于 v = v + e
     * v += e 只会计算一次 v 的值
     * 但是 v = v + e 则会计算两次 v 的值
     * 在存在副作用的情况下
     * 副作用也会被计算两次
     * a[i++] += 1
     * a[i++] = a[i++] + 1
     * 上述这条语句结果是未定义的
     */
    printf("i += 2 : %d\n", i += 2);
    printf("i -= 2 : %d\n", i -= 2);
    printf("i *= 2 : %d\n", i *= 2);
    /*
     * i *= 2 + 1 等价于 i *= (2 + 1)
     */
    printf("i *= 2 + 1 : %d\n", i *= 2 + 1);
    printf("i /= 2 : %d\n", i /= 2);
    printf("i %%= 2 : %d\n", i %= 2);

    /*
     * 复合运算符有着和 = 一样的特性
     * 它们都是右结合的
     * i += j *= 3 等价于 i += (j *= 3)
     */
    printf("i += j *= 3 : %d\n", i += j *= 3);
}

/**
 * 自增运算符和自减运算符
 * ++ --
 * 自增和自减运算符可以用于前缀也可以用于后缀
 * 后缀是左结合
 * 前缀是右结合
 */
void auto_increment_and_decrement() {
    int i, j;
    i = j = 1;

    /*
     * ++i 表示立即自增
     * i++ 表示先使用 i 的原始值随后再自增
     * 随后没有明确的时间
     * c 语言中有 顺序点 的概念
     * 应该在前一个顺序点和下一个顺序点之间对于操作数的值进行更新
     * c 语言有多种不同类型的顺序点
     * 表达式语句的末尾是其中的一种
     * 但是 i 将在下一条语句执行之前进行自增
     * -- 也具备相同的特性
     */
    printf("i is %d\n", i++);
    printf("i = %d \n", i);

    printf("j is %d\n", ++j);
    printf("j = %d\n", j);

    printf("i++ - --j : %d\n", i++ - --j);
    printf("i = %d\n", i);

    printf("-i++ : %d\n", -i++);
    printf("i = %d \n", i);
}

int main(void) {

    simple_assignment();

    compound_assignment();

    auto_increment_and_decrement();

    return 0;
}