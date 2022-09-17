/*
 * @author Anger
 * @date 2022/9/17
 * @brief 计算单词的平均长度
 */
#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void) {

    int len = 0, words_count = 1, ch;

    printf("Enter a sentence : ");

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            words_count++;
        } else {
            len++;
        }
    }

    printf("Average word length : %lf", (double)len / words_count);
}

double compute_average_word_length(const char *sentence) {
    double avg_len = 0.0;
}
