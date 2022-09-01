/*
 * @author Anger
 * @date 2022/9/1
 * @brief 循环的基础知识
 * 循环是重复执行其它语句（循环体）的一种语句
 * c 语言中，每个循环都有一个控制表达式
 * 每次执行循环体时都需要对控制表达式进行求值
 * 如果表达式为真则继续执行循环
 */
#include <stdio.h>

int i = 0, j = 10;

void sum() {
    int n, sum = 0;

    puts("Enter integers : (0 - terminate)");
    scanf("%d", &n);

    while (n != 0) {
        sum += n;
        printf("sum = %d\n", sum);
        scanf("%d", &n);
    }
}

void while_statement() {
    while (i < j)
        printf("%d ", i++);

    puts("");
    /*
     * 如果控制表达式的值始终为 true
     * 循环将不会终止，变成无限循环
     * 需要使用 break goto return 等跳出循环的语句
     * 或者调用导致程序终止的函数
     * 否则程序将不会终止
     */
    while (i) {
        printf("%4d%4d\n", j, j * j);
        j --;
        if (!j) break;
    }
}

/**
 * do while 语句本质上就是 while 语句
 * 只不过它的控制表达式的判定是在循环体结束后进行的
 * do while 语句的循环体至少会执行一次
 */
void do_while_statement() {
    i = 0;
    do {
        printf("%d ", i++);
    } while (i < 10);
    puts("");
}

/**
 * for(表达式1; 表达式2; 表达式3) {statements;}
 */
void for_statement() {
    /*
     * C99 标准的 for 循环中
     * 第一个表达式可以替换为一个声明
     * 可以声明为一个用于循环的变量
     * 如果变量 i 已经在循环前进行了声明
     * 这个语句将创建一个新的变量 i 并只用于循环内
     * for 语句声明的变量不可以在循环外进行访问
     * for 语句可以声明多个变量，只要它们的类型相同
     */
    for (int i = 0 , j = 1 ; i < 5; i++)
        printf("%d%d ", i, j);
    printf("\ni = %d  j = %d \n", i, j);
}

/**
 * break 语句跳出循环
 * 程序继续执行循环之后的语句
 * 如果循环语句出现嵌套时
 * break 语句只能跳出一层循环
 */
void break_statement() {
    puts("");
    for (int k = 0; ; ) {
        while (++k > 0) {
            if (k % 2 == 0) break;
            printf("%d ", k);
        }
        if (k == 10) break;
    }
}

/**
 * continue 语句将程序控制转移到循环体末尾之前
 * continue 语句会把程序继续留在循环内
 * continue 语句只能应用于循环中
 */
void continue_statement() {
    puts("");
    i = 0;
    while (i++ < 10) {
        if (i % 2 == 0) continue;
        printf("%d ", i);
    }
}

/**
 * goto 语句可以跳转到程序中任意有标号的语句处
 * 标号只是放置在语句开始出的标识符
 * 标识符 : 语句
 * goto 标识符
 * 大多数情况下都不需要使用 goto 语句
 * 但是在循环嵌套的情况下 goto 有时候会比较有用
 * 可以直接跳转到标号的地方
 */
void goto_statement() {
    puts("");
    i = 0;
    while (i++ >= 0) {
        if (i / 5 == 1)
            goto give_me_five;
    }
    give_me_five:
    printf("%d ", i);
}

/**
 * 银行的交互菜单
 * 点击不同的菜单
 * 执行不同的指令
 */
void checking() {
    float balance = 0.0f, credit, debit;
    int cmd;
    for (; ;) {
        puts("command 1 = credit , 2 = debit , 3 = query balance , 4 = quit");
        puts("Enter command : ");
        scanf("%1d", &cmd);
        switch (cmd) {
            case 1:
                puts("Enter credit amount : ");
                scanf("%f", &credit);
                balance += credit;
                break;
            case 2:
                puts("Enter debit amount : ");
                scanf("%f", &debit);
                balance -= debit;
                break;
            case 3:
                printf("current balance : %.2f \n", balance);
                break;
            case 4:
                goto quit;
            default:
               puts("command 1 = credit , 2 = debit , 3 = query balance , 4 = quit");
                break;
        }
    }
    quit:
    return;
}

/**
 * 空语句
 * 语句可以为空
 * 也就是除了末尾的分号其它什么都没有
 */
void empty_statement() {
    i = 0;
    for  ( ; i < 10; i ++ )
        if (i / 5 == 1) break;
    printf(" i = %d", i);

    /*
     * 空语句有一个好处就是可以编写空的循环体
     * 每次执行循环的时候先判断 1 / 5 != 1
     * 如果结果为真则循环终止
     * 普通循环转成空循环能够带来很大的好处
     * 空循环在某些情况下效率会更高
     * 并且代码也更加简洁
     */
    i = 0;
    for (; i < 10 && i / 5 != 1; i++);

    printf(" i = %d\n", i);
}

void practice_3() {
    for (int i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
        printf("%d ", i);

    puts("");
}

/*
 * 按照书上的题目
 * 这个程序最终将无限循环输出 1
 * 为了避免这种情况
 * 将表达式 2 改为了 i > 1
 * 原本是 i >= 1
 */
void practice_8() {
    for (i = 10; i > 1; i /= 2)
        printf("%d ", i++);

    puts("");
}

void practice_9() {
    printf("%d ", i = 10);
    while ((i /= 2) > 1)
        printf("%d ", i++);

    puts("");
}

void practice_12 () {
    int n;
    puts("Enter a number : ");
    scanf("%d", &n);

    for (i = 2; i * i < n; i++) {
        if (n % i == 0) {
            printf("%d is not a prime number.\n", n);
            return;
        }
    }
    printf("%d is a prime number.\n", n);
}

int main(void) {

    while_statement();

    do_while_statement();

    for_statement();

    break_statement();

    continue_statement();

    goto_statement();

    empty_statement();

    practice_3();

    practice_8();

    practice_9();

    practice_12();

    checking();

    return 0;
}