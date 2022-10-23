/*
 * @author Anger
 * @date 2022/10/23
 * @brief 输入一系列单词，以空格隔开
 * 按照相反的顺序展示出来
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

int main(void) {

    char s[MAX_LEN];
    char *p[MAX_LEN];
    int i = 0;

    printf("输入一系列以空格隔开的单词：");
    fgets(s, MAX_LEN, stdin);
    s[strlen(s) - 1] = '\0';

    if((p[i] = strtok(s, " ")) == NULL)
        return 0;
    i++;

    while ((p[i] = strtok(NULL, " ")) != NULL)
        i++;
    for (i-- ; i >= 0; --i)
        printf("%s ", p[i]);

    printf("\n");

    return 0;
}