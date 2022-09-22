/*
 * @author Anger
 * @date 2022/9/22
 * @brief 格式化单词文本
 */
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20

int main(void) {
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();

    for (;;) {
        word_len = read_word(word, MAX_WORD_LEN + 1);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }

}