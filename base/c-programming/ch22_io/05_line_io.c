/*
 * @author Anger
 * @date 2022/10/18
 * @brief 行 io
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"

void output_func(void);

void input_func(void);

int main(void) {

    output_func();

    input_func();

    return 0;
}

void output_func(void) {
    puts("abcd");
    /* fputs() 函数不会自己写换行符
     * 除非字符串中有换行符 */
    fputs("abcd", stdout);
    fputs("abcd\n", stdout);
}

void input_func(void) {
    FILE *fp = fopen(FILE_PATH, "r");
    char *string_2 = malloc(100);
    fgets(string_2, sizeof(string_2), fp);
    puts(string_2);
}
