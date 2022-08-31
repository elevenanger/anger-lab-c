/*
 * @author 刘昂林 
 * @date 2022/8/31
 * @brief 选择语句
 */
#include <stdio.h>
#include <stdbool.h>

int i = 0, j = 10;
float f = 3.14f;

/**
 * 关系运算符
 * < > <= >=
 * 与数学上的运算符相对应
 * 只是在 c 语言中运算的结果是 0(假) 或者 1(真)
 * 关系运算符是左结合的
 */
void relational_operator() {
    /* 关系运算符可以用来比较整数和浮点数 */
    printf("i < f -> %d\n", i < f);

    /*
     * 关系运算符的优先级小于算数运算符
     * i + 1 < j + 2
     * 等价于
     * (i + i) < (j + 2)
     */
    printf("i + 1 < j + 2 -> %d\n", i + 1 < j + 2);

    /*
     * 表达式 i < j < f 在 c 语言中是合法的
     * 但是得到的可能不是锁期望的结果
     * 因为 < 运算符是左结合的
     * 所以这个表达式等价于 (i < j) = 0 < f
     */
    printf("i < j < f -> %d\n", i < j < f);
}

/**
 * 判等运算符
 * == !=
 * 与关系运算符一样
 * 判等运算符也是左结合的
 * 也是产生 0 或者 1 的结果
 * 但是判等运算符的优先级低于关系运算符
 */
void equality_operator() {
    printf("i < j == i <= j -> %d\n", i < j == i <= j);
}

/**
 * 逻辑运算符
 * ! 是一元运算符
 * && || 是二元运算符
 * 逻辑运算符产生的结果是 0 或 1
 * 操作数的值经常是 0 或者 1
 * 但是这不是必须的
 * 逻辑运算符将任何非零值操作数都当做真值来处理
 * 将零值作为假值操作数来处理
 */
void logical_operator() {
    printf("!i -> %d\n", !i);
    /*
     * && 和 || 都对操作数进行短路计算
     * 首先计算左操作数然后计算右操作数
     * 如果左操作数的值可以推导出表达式的值
     * 那么将不再计算右操作数
     */
    printf("(i != 0) && j > 0 -> %d\n", (i != 0) && j > 0);
    /*
     * 注意短路的特性
     * 操作数的副作用不会总是发生
     */
    printf("i > 0  && ++j > 0 -> %d\n", i > 0  && ++j > 0);
    printf("i = %d j = %d\n", i, j);
    printf("++i > 0  && ++j > 0 -> %d\n", ++i > 0  && ++j > 0);
    printf("i = %d j = %d\n", i, j);
}

/**
 * if 语句允许程序从通过测试表达式的两种选项中选择一种
 */
void if_statement() {
    if (i > 0)
        printf("%d > 0 \n", i);

    /*
     * 如果一个 if 语句中处理两条或者多条语句
     * 使用复合语句
     * {statement1;statement2;...}
     */
    if (i > 0) {
        puts("compound statement");
        printf("%d > 0 \n", i);
    } else if (i > 1) {
        puts("else if statement");
    } else {
        puts("else statement");
    }
}

/**
 * 条件表达式
 * 表达式1 ? 表达式2 : 表达式3
 * 读法：如果表达式 1 成立，那么表达式 2，否则表达式 3
 * 求值步骤：首先计算表达式 1 的值
 * 如果值不为 0 那么计算表达式 2 的值就是整个表达式的值
 * 如果表达式 1 的值为 0 那么表达式 3 的值就是整个表达式的值
 * 条件表达式是 c 语言中唯一一个需要三个操作数的运算符
 * 所以也称为三元运算符
 * 除了赋值运算符，条件运算符的优先级低于之前提到的所有运算符
 */
void conditional_operator() {
    printf("i == 0 ? i + 10 : i * 10  -> %d\n", i == 0 ? i + 10 : i * 10);
    /*
     * 如果条件表达式中 int 和 float 型混合在一起时
     * 表达式的类型是 float 型
     * 如果 1 != 0 为真
     * 那么变量 i 转换为 float 型后的值就是表达式的值
     */
    printf("i != 0 ? i : f -> %.2f\n", i != 0 ? i : f);
}

/**
 * C99 标准中布尔值实际上就是整数类型
 * _Bool 表示布尔类型变量
 * 一般来说，布尔值类型变量只能赋值 0 或者 1
 * 往 _Bool 类型变量赋任何非零值都会导致变量赋值为 1
 * 除此之外的，stdbool.h 头还提供一种 bool 宏，是的操作布尔值更容易
 * 其中提供了 true 和 false 两个宏，分别代表 0 和 1
 */
void bool_value() {
    _Bool flag ;
    flag = 4;
    printf("_Bool flag is : %d\n", flag);

    bool bool_flag = false;
    printf("bool_flag is : %d\n", bool_flag);
}

/**
 * switch 语句
 * switch (控制表达式) {
 *    case 常量表达式: 语句;
 *    default : 语句;
 * }
 * switch 后面必须跟着圆括号括起来的整型控制表达式
 * c 语言把字符当做整型来处理
 * 所以 switch 语句可以对字符进行判定
 * 但是不能对浮点数和字符串进行判定
 * 常量表达式很像普通的表达式
 * 只是不能包含变量和函数调用
 * 常量表达式的值必须是整数
 * 每个分支标号后面都可以跟任意数量的语句
 * 不需要使用花括号括起来
 * 没组语句最后一般是 break 语句
 * c 语言不允许有重复的分支标号
 * 但是对于分支顺序没有要求
 * default 不一样要放在最后
 * switch 语句是基于计算的跳转
 * 对控制表达式求值时
 * 控制会跳转到与 switch 语句表达式相匹配的分支处
 * 在执行完分支标号的最后一条语句之后
 * 程序控制向下跳转到下一个分支标号
 * 如果没有 break 语句
 * 控制将会从一个分支继续到下一个分支
 */
void switch_statement(int ops) {
    switch (ops) {
        case 1:
            puts("one");
        case 2:
            puts("two");
        case 3:
            puts("three");
            break;
        default:
            puts("everything!");
    }
}

void legal_date_format() {
    int year, month, day;

    puts("Enter Date (mm/dd/yyyy) : ");
    scanf("%2d%2d%4d", &month, &day, &year);

    printf("Dated this : %d", day);

    switch (day) {
        case 1:
        case 11:
        case 21:
        case 31:
            printf("st");
            break;
        case 2:
        case 12:
        case 22:
            printf("nd");
            break;
        case 3:
        case 13:
        case 23:
            printf("rd");
            break;
        default:
            printf("th");
    }

    printf(" day of ");
    switch (month) {
        case 1: printf("Jan"); break;
        case 2: printf("Feb"); break;
        case 3: printf("Mar"); break;
        case 4: printf("Apr"); break;
        case 5: printf("May"); break;
        case 6: printf("Jun"); break;
        case 7: printf("Jul"); break;
        case 8: printf("Aug"); break;
        case 9: printf("Sep"); break;
        case 10: printf("Oct"); break;
        case 11: printf("Nov"); break;
        case 12: printf("Dec"); break;
        default: printf("Error !");
    }

    printf(", %d", year);
}

int main(void) {
    printf("i = %d, j = %d, f = %.2f\n", i, j, f);

    relational_operator();

    equality_operator();

    logical_operator();

    if_statement();

    conditional_operator();

    bool_value();

    switch_statement(1);

    legal_date_format();

    return 0;
}