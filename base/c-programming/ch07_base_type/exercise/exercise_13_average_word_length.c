/*
 * @author Anger
 * @date 2022/9/3
 * @brief 计算一个句子中所有单词的平均长度
 * 单词与单词之间只有一个空格
 * 最后的标点符号视为最后一个单词的一部分
 */
#include <stdio.h>

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