/*
 * @author Anger
 * @date 2022/9/17
 * @brief 计算单词的平均长度
 */
#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void) {

    char sentence[100], *ch = sentence;

    printf("Enter a sentence : ");
    while ((*ch++ = getchar()) != '\n');
    *(ch - 1) = '\0';

    printf("Average word length : %.2lf", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence) {
    int words_count = 0, len = 0;
    do {
        printf("%c", *sentence);
        if (*sentence == ' ')
            words_count++;
        else
            len++;
    } while (*++sentence != '\0');
    words_count++;
    printf("words_count => %d, len => %d\n", words_count, len);

    return (double) len / words_count;
}
