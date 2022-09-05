/*
 * @author Anger
 * @date 2022/9/5
 * @brief 修改 7-4
 * 给输出加上标签
 */
#include <stdio.h>
#define DIGIT 15

int main(void) {
    int i = 0;
    char ch;
    char phone_number[DIGIT];

    printf("Enter phone number : ");

    while (i < DIGIT && (ch = (char) getchar()) != '\n') {
        switch (ch) {
            case 'A': case 'B': case 'C': ch = '2'; break;
            case 'D': case 'E': case 'F': ch = '3'; break;
            case 'G': case 'H': case 'I': ch = '4'; break;
            case 'J': case 'K': case 'L': ch = '5'; break;
            case 'M': case 'N': case 'O': ch = '6'; break;
            case 'P': case 'Q': case 'R': case 'S': ch = '7'; break;
            case 'T': case 'U': case 'V': ch = '8'; break;
            case 'W': case 'X': case 'Y': case 'Z': ch = '9'; break;
            default: break;
        }
        phone_number[i] = ch;
        i++;
    }

    printf("In numeric form : ");
    for (int j = 0; j < i; ++j)
        printf("%c", phone_number[j]);

    return 0;
}
