/*
 * @author Anger
 * @date 2022/9/11
 * @brief 七段显示器
 */
#include <stdio.h>
#include <stdbool.h>

/* 最大的数字数量 */
#define MAX_DIGIT 10
/* 七段显示下数字的高度 */
#define NUM_HEIGHT 3
/* 七段显示下数字的宽度 */
#define NUM_WIDTH 4

/* 表示每个数字和段的对应关系 */
const int segments[10][7] = {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
};
/* 数字在七段显示下的字符值数组 */
char digits[NUM_HEIGHT][MAX_DIGIT * NUM_WIDTH];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
    char ch;
    int pos = 0;
    clear_digits_array();
    printf("Enter a number : ");

    while ((ch = getchar()) != '\n') {
        if (ch >= '0' && ch <= '9')
            /* 将数值字符减去 '0' 字符,获取对应的整数值 */
            process_digit(ch - '0', pos++);
    }
    print_digits_array();
    return 0;
}

void clear_digits_array(void) {
    for (int i = 0; i < NUM_HEIGHT; ++i)
        for (int j = 0; j < NUM_WIDTH * MAX_DIGIT; ++j)
            digits[i][j] = ' ';
}

/**
 * 将数字和数字的位置与七段的位值进行映射
 * @param digit 数字
 * @param position 数字的位置
 */
void process_digit(int digit, int position) {
    if (segments[digit][0] == 1)
        digits[0][NUM_WIDTH * position + 1] = '_';
    else
        digits[0][NUM_WIDTH * position + 1] = ' ';
    if (segments[digit][1] == 1)
        digits[1][NUM_WIDTH * position + 2] = '|';
    else
        digits[1][NUM_WIDTH * position + 2] = ' ';
    if (segments[digit][2] == 1)
        digits[2][NUM_WIDTH * position + 2] = '|';
    else
        digits[2][NUM_WIDTH * position + 2] = ' ';
    if (segments[digit][3] == 1)
        digits[2][NUM_WIDTH * position + 1] = '_';
    else
        digits[2][NUM_WIDTH * position + 1] = ' ';
    if (segments[digit][4] == 1)
        digits[2][NUM_WIDTH * position] = '|';
    else
        digits[2][NUM_WIDTH * position] = ' ';
    if (segments[digit][5] == 1)
        digits[1][NUM_WIDTH * position] = '|';
    else
        digits[1][NUM_WIDTH * position] = ' ';
    if (segments[digit][6] == 1)
        digits[1][NUM_WIDTH * position + 1] = '_';
    else
        digits[1][NUM_WIDTH * position + 1] = ' ';
}

void print_digits_array(void) {
    for (int i = 0; i < NUM_HEIGHT; ++i) {
        for (int j = 0; j < NUM_WIDTH * MAX_DIGIT; ++j)
            printf("%c", digits[i][j]);
        puts("");
    }
}