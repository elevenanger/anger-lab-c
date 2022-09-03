/*
 * @author Anger
 * @date 2022/9/3
 * @brief 十字拼字游戏
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    int ch ,sum = 0;

    printf("Enter a word : ");

    while ((ch = getchar()) != '\n') {
        switch (toupper((char) ch)) {
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
    printf("Scrabble value : %d", sum);

    return 0;
}
