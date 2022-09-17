/*
 * @author Anger
 * @date 2022/9/17
 * @brief 改进 planet.c 字符串比较的时候可以忽略大小写
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int my_str_cmp(const char *string1, const char *string2);

int main(int argc, char *argv[]) {

    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    int i, j;

    for (i = 1; i < argc; ++i) {
        for (j = 0; j < NUM_PLANETS; ++j) {
            if (my_str_cmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

int my_str_cmp(const char *string1, const char *string2) {
    int diff = 0;
    for (int i = 0; string1[i] != '\0' && string2[i] != '\0'; ++i)
        diff += (tolower(string1[i]) - tolower(string2[i]));
    if (diff == 0 ) {
        if (strlen(string1) > strlen(string2))
            diff += 1;
        else if (strlen(string1) < strlen(string2))
            diff -= 1;
    }
    return diff;
}
