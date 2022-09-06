/*
 * @author Anger
 * @date 2022/9/6
 * @brief 凯撒加密
 */
#include <stdio.h>

char shift_forward(char c, int offset) {
    if (c >= 'a' && c <= 'z')
        c = (char) (((c - 'a') + offset) % 26 + 'a');
    else if (c >= 'A' && c <= 'Z')
        c = (char) (((c - 'A') + offset) % 26 + 'A');
    return c;
}

int main(void) {
    int i = 0, offset;
    char c;
    char message[80];

    printf("Enter a message : ");

    while ((c = (char) getchar()) != '\n')
        message[i++] = c;

    printf("Enter shift amount (1 - 25) : ");

    scanf("%d", &offset);

    puts("");

    for (int j = 0; j < i; ++j)
        printf("%c", shift_forward(message[j], offset));

    return 0;
}
