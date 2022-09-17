/*
 * @author Anger
 * @date 2022/9/17
 * @brief 十字拼字游戏
 */
#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *sequence);

int main(void) {
    char words[20];
    printf("Enter a word : ");
    scanf("%s", words);
    printf("scrabble value => %d\n", compute_scrabble_value(words));
    return 0;
}

int compute_scrabble_value(const char *sequence) {
    char ch;
    int sum = 0;
    while ((ch = *sequence++) != '\0') {
        switch (toupper(ch)) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                sum += 1;
                break;
            case 'D':
            case 'G':
                sum += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                sum += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                sum += 4;
                break;
            case 'K':
                sum += 5;
                break;
            case 'J':
            case 'X':
                sum += 6;
                break;
            default:sum += 0;
        }
    }
    return sum;
}
