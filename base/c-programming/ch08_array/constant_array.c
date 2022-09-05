/*
 * @author Anger
 * @date 2022/9/5
 * @brief 常量数组
 */
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SIZE(a) (int) sizeof(a) / sizeof(a[0])
#define NUM_SUITS 4
#define NUM_RANKS 13

/**
 * 无论是一维还是多维数组
 * 都可以在声明的最开始处适用 const 关键字声明为常量数组
 * 程序不应该对声明为 const 的数组进行修改
 */
void declare_const_arr() {
    const char char_arr[] = {'A', 'B', 'C', '0'};
    for (int i = 0; i < SIZE(char_arr); ++i)
        printf("%c ", char_arr[i]);
}

void deal() {
    /* 手牌数组，默认为 false ，一旦持有某张牌则设置为 true */
    bool in_hand[NUM_SUITS][NUM_RANKS]  = {false};
    /* 手牌数量 牌面 花色 */
    int num_cards, rank, suit;
    /* 牌面值 */
    const char rank_code[] = {'2', '3', '4', '5', '6', '7','8',
                              '9', 't', 'j', 'q', 'k', 'a'};
    /* 花色 */
    const char suit_code[] = {'c', 'd', 'h', 's'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand : ");
    scanf("%d", &num_cards);

    printf("\nyour hand : ");
    while (num_cards > 0) {
        /* 随机花色 */
        suit = rand() % NUM_SUITS;
        /* 随机牌面 */
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    puts("");
}

/**
 * 变长数组
 * 数组变量的长度必须由常量表达式定义
 * 但是在 C99 中，可以使用非常量表达式
 * 变长数组的长度是在程序执行时计算的
 * 而不是程序编译时计算
 * 变长数组的有点是不必在构造数组的时候指定数组的长度
 * 在执行时准确计算数组的长度
 * 避免造成数组过长或者过短的问题
 */
void reverse() {
    int i,n;
    printf("How many numbers do you want to reverse : ");
    scanf("%d", &n);

    /* 使用了变量作为数组的长度 */
    int a[n];
    printf("\nEnter %d numbers.", n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
}

int main(void) {

    declare_const_arr();

    deal();

    reverse();

    return 0;
}