/*
 * @author Anger
 * @date 2022/9/19
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(const char *message);

int main(void) {
    char message[100], c, *m = message;

    printf("Enter a message : ");
    while ((c = getchar()) != '\n')
        *m++ = c;
    *m = '\0';

    if (is_palindrome((message)))
        printf("%s => is palindrome\n", message);
    else
        printf("%s => is not palindrome\n", message);

    return 0;
}

bool is_palindrome(const char *message) {
    const char *p = message, *q = &message[strlen(message) - 1];
    while (q >= p) {
        if (tolower(*p++) != tolower(*q--))
            return false;
    }
    return true;
}
