/*
 * @author Anger
 * @date 2022/9/19
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void) {

    char word1[20], word2[20], *p, ch;

    printf("Enter word 1 : ");
    p = word1;
    while ((ch = getchar()) != '\n')
        *p++ = ch;
    *p = '\0';

    printf("Enter word 2 : ");
    p = word2;
    while ((ch = getchar()) != '\n')
        *p++ = ch;
    *p = '\0';

    if (are_anagrams(word1, word2))
        printf("%s %s are anagrams", word1, word2);
    else
        printf("%s %s are not anagrams", word1, word2);

    return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
    int alpha_digit[26] = {0};
    char c;

    while ((c = *word1++)) {
        if (!isalpha(c))
            continue;
        alpha_digit[tolower(c) - 'a']++;
    }

    while ((c = *word2++)) {
        if (!isalpha(c))
            continue;
        alpha_digit[tolower(c) - 'a']--;
    }

    for (int i = 0; i < 26; ++i){
        if (alpha_digit[i] != 0)
            return false;
    }

    return true;
}
