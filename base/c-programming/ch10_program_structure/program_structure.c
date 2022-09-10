/*
 * @author Anger
 * @date 2022/9/10
 * @brief 构建 c 程序
 * 推荐的编排顺序
 * #include 指令
 * #define 指令
 * 类型定义
 * 外部变量的声明
 * main 函数以外的函数原型
 * main 函数定义
 * 其它函数定义
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/* 牌面值 */
#define NUM_RANKS 13
/* 花色 */
#define NUM_SUITS 4
/* 手牌张数 */
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
/* 顺子 同花 四张 三张*/
bool straight, flush, four, three;
/* 对子数量 */
int pairs;

/* 读入一手牌 */
void read_cards(void);
/* 分析手牌的顺子、对子等 */
void analyse_hand(void);
/* 显示一手牌的分类 */
void print_result(void);

int main(void) {
    read_cards();
    analyse_hand();
    print_result();
    return 0;
}

void read_cards(void) {
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    /*未读入手牌之前，将所有的标识位置位false*/
    for (rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
            card_exists[rank][suit] = false;
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card : ");

        rank_ch = getchar();
        switch (toupper(rank_ch)) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't': rank = 8; break;
            case 'j': rank = 9; break;
            case 'q': rank = 10; break;
            case 'k': rank = 11; break;
            case 'a': rank = 12; break;
            default: bad_card = true;
        }

        suit_ch = getchar();
        switch (tolower(suit_ch)) {
            case 'c': suit = 0; break;
            case 'd': suit = 1; break;
            case 'h': suit = 2; break;
            case 's': suit = 3; break;
            default: bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("ignore bad card");
        else if (card_exists[rank][suit])
            printf("Duplicate card;ignored.\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyse_hand(void) {
    int num_consec = 0;
    int rank, suit;

    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /*检查是否同花*/
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            flush = true;


    rank = 0;
    /* 遍历 num_in_rank 数组，找到第一个牌面值出现次数不为 0 的牌面值 */
    while (num_in_rank[rank] == 0) rank++;
    printf("rank = %d\n", rank);
    /* 如果连续五个代表牌面值出现次数都不为 0 说明是顺子 */
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++) {
        num_consec++;
        if (num_consec == NUM_CARDS) {
            straight = true;
            return;
        }
    }

    for (rank = 0; rank < NUM_RANKS; rank++) {
        /* 某个点数值为 4 四张为 true */
        if (num_in_rank[rank] == 4) four = true;
        /* 某个点数为 3  三张为 true */
        if (num_in_rank[rank] == 3) three = true;
        /* 某个点数为 2 加一对对子*/
        if (num_in_rank[rank] == 2) pairs++;
    }
}

void print_result(void) {
    if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High Card");

    printf("\n\n");
}