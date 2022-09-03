/*
 * @author Anger
 * @date 2022/9/3
 * @brief 输入字符，统计其中出现元音字母的次数
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {

    int ch, count = 0;

    printf("Enter a sentence : ");

    while ((ch = getchar()) != '\n') {
        switch (toupper(ch)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count += 1;
                break;
            default:
                continue;
        }
    }

    printf("Your sentence contains %d vowels", count);

    return 0;
}
