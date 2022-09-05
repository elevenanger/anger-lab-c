/*
 * @author Anger
 * @date 2022/9/5
 * @brief 将输入的信息转换成 b1ff 公告
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {

    int i;
    char ch;
    char message[100];

    printf("Enter message : ");
    ch = toupper(getchar());
    for (i = 0; ch != '\n'; ++i) {
        switch (ch) {
            case 'A': ch = '4'; break;
            case 'E': ch = '3'; break;
            case 'I': ch = '1'; break;
            case 'O': ch = '0'; break;
            case 'S': ch = '5'; break;
            default: break;
        }
        message[i] = ch;
        ch = toupper(getchar());
    }

    for (int j = 0; j < i; ++j)
        putchar(message[j]);
    printf("!!!!!!!!");

    return 0;
}