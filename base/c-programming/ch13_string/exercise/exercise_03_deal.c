/*
 * @author Anger
 * @date 2022/9/17
 * @brief 显示牌的全名
 */
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))
#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
        /* 手牌数组，默认为 false ，一旦持有某张牌则设置为 true */
    bool in_hand[NUM_SUITS][NUM_RANKS]  = {false};
    /* 手牌数量 牌面 花色 */
    int num_cards, rank, suit;
    /* 牌面值 */
    const char *rank_code[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                              "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    /* 花色 */
    const char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand : ");
    scanf("%d", &num_cards);

    printf("\nYour hand : \n");
    while (num_cards > 0) {
        /* 随机花色 */
        suit = rand() % NUM_SUITS;
        /* 随机牌面 */
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }
    return 0;
}