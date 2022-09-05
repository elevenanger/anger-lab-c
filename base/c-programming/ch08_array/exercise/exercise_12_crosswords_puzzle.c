/*
 * 修改 7-5
 * 使用数组存储每个字母的字面值
 * 读取输入单次中的每一个字母
 * 利用该数组确定字面值
 * 使用数组的初始化式来初始化该数组
 */
#include <stdio.h>
#include <ctype.h>
#define CHAR_NUM 26

int main(void) {

    int ch, sum = 0;

    int char_val[CHAR_NUM] =
            {[0] = 1, [1] = 3, [2] = 3, [3] = 2, [4] = 1,
              [5] = 4, [6] = 2, [7] = 4, [8] = 1, [9] = 6,
              [10] = 5, [11] = 1, [12] = 3, [13] = 1, [14] = 1,
              [15] = 3, [16] = 0, [17] = 1, [18] = 1, [19] = 1,
              [20] = 1, [21] = 4, [22] = 4, [23] = 6, [24] = 4, [25] = 0};

    printf("Enter a word : ");

    while ((ch = getchar()) != '\n') {
        sum += char_val[toupper(ch) - 'A'];
    }
    printf("Scrabble value : %d", sum);

    return 0;
}