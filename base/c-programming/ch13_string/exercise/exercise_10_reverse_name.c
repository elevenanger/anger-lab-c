/*
 * @author Anger
 * @date 2022/9/17
 * @brief
 */
#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

int main(void) {
    char name[20];
    int i = 0;
    printf("enter name : ");
    while ((name[i++] = (char) getchar()) != '\n');
    name[i - 1] = '\0';
    reverse_name(name);
    return 0;
}

void reverse_name(char *name) {
    printf("name => %s\n", name);
    char *p = name;
    int n = 0;
    char first_name[20], last_name[20];
    while (*p++ != ' ')
        n++;
    strncpy(first_name, name, n);
    first_name[n] = '\0';
    strcpy(last_name, p);
    printf("reverse %s => %s, %1s.", name, last_name, first_name);
}
