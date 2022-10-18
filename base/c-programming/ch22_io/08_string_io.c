/*
 * @author Anger
 * @date 2022/10/18
 * @brief 字符串的输入和输出
 */
#include <stdio.h>
#include <stdlib.h>

void output_func(void);
void input_func(void);

int main(void) {
    output_func();
    input_func();
    return 0;
}

void output_func(void) {
    char *string = malloc(20);
    /* sprintf 函数把输出写入字符数组中而不是流中
     * 第二个参数是格式串
     * sprintf 很方便用于数据的格式化 */
    sprintf(string, "%d/%d/%d", 9, 20, 2022);
    puts(string);
    /* snprintf 多了一个参数 n
     * 写入的字符数不超过 n - 1*/
    snprintf(string, 10, "%s, %s", "Eleven", "Anger");
    puts(string);
}

void input_func(void) {
    char *string = "Hallelujah", c1, c2;
    /* sscanf() 从字符串中而不是流中读取数据 */
    sscanf(string, "%c%c", &c1, &c2);
    printf("c1 => %c c1=> %c\n", c1, c2);
}
