/*
 * @author Anger
 * @date 2022/9/8
 * @brief 掷骰子游戏
 * 玩家一次掷两枚骰子
 * 如果点数之和为 7 或者 11 则获胜
 * 2 3 12 则落败
 * 其它情况下的点数之和为 目标
 * 后续的投掷
 * 如果再次掷出目标点数则获胜
 * 掷出 7 则落败
 * 每次游戏结束后询问玩家是否再玩一次
 * 如果回答不是 y 或者 Y 则结束
 * 程序会显示胜负次数
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NUM_OF_DICE 6

int roll_dice(void);
bool play_game(void);

int roll_dice(void) {
    int num1 = rand() % NUM_OF_DICE, num2 = rand() % NUM_OF_DICE;
    printf("Your rolled : %d\n", num1 + num2);
    return num1 + num2;
}


bool play_game(void) {
    int point;
    switch ((point = roll_dice())) {
        case 7:
        case 11:
            printf("You Win!\n");
            return true;
        case 2:
        case 3:
        case 12:
            printf("You Lose!\n");
            return false;
        default:
            printf("Your point is : %d\n", point);
            break;
    }

    int roll_number;
    while (true) {
        roll_number = roll_dice();
        if (roll_number == 7) {
            printf("You Lose !\n");
            return false;
        } else if (roll_number == point){
            printf("You win !\n");
            return true;
        }
    }
}

int main(void) {

    srand((unsigned int) time(NULL));

    int win_count = 0, lose_count = 0;
    char c;

    do {
        play_game() ?  win_count++ : lose_count++;
        printf("Play again? ");
        c = getchar();
        printf("%c\n", c);
        while (getchar()!='\n');
    }
    while (tolower(c) == 'y');

    printf("Win count => %d\n"
           "Lose count => %d\n", win_count, lose_count);

    exit(EXIT_SUCCESS);
}