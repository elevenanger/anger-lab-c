/*
 * @author Anger
 * @date 2022/9/9
 * @brief 外部变量
 * 函数可以通过外部变量进行通信
 * 外部变量是声明在任何函数体之外的
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define STACK_SIZE 100

/*
 * 外部变量
 * 静态存储期：和 static 变量一样，外部变量具有静态存储期
 * 存储在外部变量的值将会被永久保存下来
 * 文件作用域 ：外部变量拥有文件作用域
 * 从变量被声明的点开始一直到所在文件的末尾
 * 因此，跟随在外部变量声明之后的函数都可以访问并修改它
 *
 * 使用外部变量时 要确保它们都有有意义的名字
 * 局部变量不是总需要有意义的名字
 *
 * 实现栈的数据结构
 * 栈和数组一样可以存储同样数据结类型的多个数据项
 * 栈只能压入数据项（将数据项加载异端-"栈顶"）
 * 或者从栈中弹出数据项（从同一端移走数据项）
 *
 * 将栈的元素存储在数组 contents 中
 */
int contents[STACK_SIZE];
/* top 的一个用来标记栈顶的位置
 * 栈为空时 top = 0
 * 压入数据项时
 * 把数据项存储在 top 的位置 自增 top
 * 取出数据时 自减 top 用它做为索引取出弹出的数据项 */
int top = 0;

/**
 * 将栈置位空
 * 将 top 置位 0
 */
void make_empty(void) {
    top = 0;
}

/**
 * 判断栈是否为空栈
 * @return top 是否为 0
 */
bool is_empty(void) {
    return top == 0;
}

/**
 * 判断栈中元素是否已满
 * @return 判断 top 的数量是否达到栈的大小
 */
bool is_full(void) {
    return top == STACK_SIZE;
}

/**
 * 往栈中压入元素
 * @param i 元素
 */
void push(int i) {
    /* 如果已经到达栈大小的上线，则提示栈上溢，结束程序*/
    if (is_full()) {
        printf("stack overflow!");
        exit(EXIT_FAILURE);
    } else {
        /* 往栈中写入元素,栈顶位置 + 1 */
        contents[top++] = i;
    }
}

int pop(void) {
    if (is_empty()) {
        /*栈为空试图取出元素，提示栈下溢，结束程序*/
        printf("stack underflow!");
        exit(EXIT_FAILURE);
    } else {
        return contents [--top];
    }
}

void test_stack() {
    for (int j = 0; j < 10000; ++j)
        if (!is_full())
            push(j);
        else break;

    while (!is_empty())
        printf("%d ", pop());

    puts("");
}

/* 随机数 */
int random_number;

/*
 * 产生一个 1~100 的随机数
 * 赋值给全局变量
 */
void generate_random_number(void) {
    srand((unsigned)time(NULL));
    random_number = (rand() % 100) + 1;
}

/**
 * 猜数游戏
 * 输入的数字与全局变量 random_number 做比较
 * 直到二者相等
 */
void guess_number(void) {
    printf("Guess the secrete number between 1 ~ 100\n");
    /* 产生一个随机数，对全局变量进行赋值 */
    generate_random_number();
    printf("A new number has been chosen.\n");
    bool bingo = false;
    int count = 0;
    while (!bingo) {
        printf("Enter guess : ");
        int guess_number;
        scanf("%d", &guess_number);
        count++;
        if (guess_number < random_number)
            printf("too low !\n");
        else if (guess_number > random_number)
            printf("too high!\n");
        else if (guess_number == random_number) {
            printf("bingo\n");
            bingo = true;
        }
        if (getchar() == '\n') continue;
    }
    printf("You won in %d guesses!\n", count);
}

void play_guess_number_game() {
    char c;
    do {
        guess_number();
        printf("Play again ?\n");
        scanf("%c", &c);
        puts("");
    } while (toupper(c) == 'Y');
}

int main(void) {

    test_stack();

    play_guess_number_game();

    return 0;
}