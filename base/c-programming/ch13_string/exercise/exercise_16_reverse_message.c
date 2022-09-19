/*
 * @author Anger
 * @date 2022/9/19
 */
#include <stdio.h>
#include <string.h>

void reverse(char *message);

int main(void) {
    char message[100], *p = message, ch;
    printf("Enter a message : ");
    while ((ch = getchar()) != '\n') {
        *p++ = ch;
    }
    *p = '\0';
    reverse(message);
    printf("Reverse message => %s\n", message);
    return 0;
}

void reverse(char *message) {
    char c;
    char *p = message, *q = &message[strlen(message) - 1];
    while (q - p >= 0) {
        c = *p;
        *p = *q;
        *q = c;
        p++;
        q--;
    }
}
