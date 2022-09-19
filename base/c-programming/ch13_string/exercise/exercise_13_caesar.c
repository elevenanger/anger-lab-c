/*
 * @author Anger
 * @date 2022/9/19
 */
#include <stdio.h>

void encrypt(char *message, int shift);
char shift_forward(char c, int shift);

int main(void) {

    char message[80];
    int shift;

    printf("Enter message : ");

    scanf("%s", message);


    printf("Enter shift amount (1 - 25) : ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("encrypted message => %s", message);

    return 0;
}

void encrypt(char *message, int shift) {
    char *p = message;
    while (*p) {
        *p= shift_forward(*p, shift);
        p++;
    }

}

char shift_forward(char c, int shift) {
    if (c >= 'a' && c <= 'z')
        c = (char) (((c - 'a') + shift) % 26 + 'a');
    else if (c >= 'A' && c <= 'Z')
        c = (char) (((c - 'A') + shift) % 26 + 'A');
    return c;
}
