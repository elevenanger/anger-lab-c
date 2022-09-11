/*
 * @author Anger
 * @date 2022/9/11
 * @brief 修改 poker 程序
 * 将 num_in_rank num_in_suits card_exists 从程序中去掉
 * 改用 5 * 2 的数组来存储牌
 * 数组的每一行表示一张牌
 * hand[0][0] 表示第一张牌的点数
 * hand[0][1] 表示第一张牌的花色
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
/* 手牌信息 第一位表示点数，第二位表示花色 */
#define CARDS_INFO 2

/* 手牌信息 第一位表示点数，第二位表示花色 */
int hand[NUM_CARDS][CARDS_INFO];

/* 同花大顺 同花大顺 顺子 同花 四张 三张*/
bool small_straight, straight, flush, four, three;
/* 对子数量 */
int pairs;

/* 读入一手牌 */
void read_cards(void);
/* 分析手牌的顺子、对子等 */
void analyse_hand(void);
/* 显示一手牌的分类 */
void print_result(void);
/* 检查一张牌是否已经在手牌中 */
bool is_exist_cards(int rank, int suit);
void is_flush(void);
void is_straight(void);
void rank_count(void);
void hand_card_sort_by_rank(int arr[NUM_CARDS][CARDS_INFO], int n);
void print_hand(void);

int main(void) {
    read_cards();
    analyse_hand();
    print_result();
    return 0;
}

void read_cards(void) {

    for (int i = 0; i < NUM_CARDS; ++i)
        for (int j = 0; j < CARDS_INFO; ++j)
            hand[i][j] = -1;

    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card : ");

        rank_ch = getchar();
        switch (tolower(rank_ch)) {
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
            default: bad_card = true; break;
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
        else if (is_exist_cards(rank, suit))
            printf("Duplicate card;ignored.\n");
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

void analyse_hand(void) {
    is_flush();
    is_straight();
    rank_count();
}

void print_result(void) {
    print_hand();
    if (straight && flush && hand[0][0] == 8) printf("Royal Flush");
    else if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (small_straight) printf("Small straight");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High Card");

    printf("\n\n");
}

bool is_exist_cards(int rank, int suit) {
    for (int i = 0; i < NUM_CARDS; ++i)
        if (rank == hand[i][0] && suit == hand[i][1])
            return true;
    return false;
}

void is_flush(void) {
    /* 将同花的标识位初始化为 true */
    flush = true;
    /* 检查是否同花 */
    for (int i= 1; i < NUM_CARDS; i++)
        /* 遍历手牌中所有牌的花色
         * 和前一张牌的花色进行比较
         * 如果一张牌的花色不相同则说明不是同花
         */
        if (hand[i][1] != hand[i - 1][1])
            flush = false;

    printf("flush => %d\n", flush);
}

void is_straight(void) {
    /* 首先按照牌面值对手牌排序 */
    hand_card_sort_by_rank(hand, NUM_CARDS);

    straight = true;
    /* 如果后一张牌的牌面值与前一张的牌面值相差不为一，说明不是顺子 */
    for (int i = 1; i < NUM_CARDS; ++i) {
        if (hand[i][0] - hand[i - 1][0] != 1)
            straight = false;
    }

    small_straight = true;
    if (hand[NUM_CARDS - 1][0] != 12) small_straight = false;
    for (int i = 0; i < NUM_CARDS; ++i) {
        if (i < NUM_CARDS - 1)
            if (i != hand[i][0])
                small_straight = false;
    }
}

void hand_card_sort_by_rank(int arr[NUM_CARDS][CARDS_INFO], int n) {
    int max[CARDS_INFO], index = 0;
    max[0] = arr[0][0];
    max[1] = arr[0][1];

    for (int i = 1; i < n; ++i)
        if (arr[i][0] > arr[i - 1][0]) {
            max[0] = arr[i][0];
            max[1] = arr[i][1];
            index = i;
        } else {
            max[0] = arr[i - 1][0];
            max[1] = arr[i - 1][1];
            index = i - 1;
        }

    arr[index][0] = arr[n - 1][0];
    arr[index][1] = arr[n - 1][1];

    arr[n - 1][0] = max[0];
    arr[n - 1][1] = max[1];

    if (--n > 0)
        hand_card_sort_by_rank(arr, n);

}

void rank_count(void) {
    four = false;
    three = false;
    pairs = 0;
    int rank_count[NUM_RANKS] = {0};
    for (int i = 0; i < NUM_CARDS; ++i)
        rank_count[hand[i][0]] ++;

    for (int i = 0; i < NUM_RANKS; ++i)
        if (rank_count[i] == 4) four = true;
        else if (rank_count[i] == three) three = true;
        else if (rank_count[i] == 2) pairs++;
}

void print_hand(void) {
    for (int i = 0; i < NUM_CARDS; ++i) {
        printf("hand[%d][%d] => %d ", i, 0, hand[i][0]);
        printf("hand[%d][%d] => %d\n", i, 1, hand[i][1]);
    }
}