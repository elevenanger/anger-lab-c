/*
 * @author Anger
 * @date 2022/10/23
 * @brief 从标注输入读取数据
 * 统计句子数量
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char c, d = '\0';
    int count = 0;

    while ((c = getchar()) != EOF) {
        if (strchr(".?!", d) != NULL && isspace(c))
            count++;
        d = c;
    }

    printf("句子数量 %d\n", count);

    return 0;
}