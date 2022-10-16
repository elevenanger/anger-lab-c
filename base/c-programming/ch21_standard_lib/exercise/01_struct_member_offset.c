/*
 * @author Anger
 * @date 2022/10/16
 * @brief 结构成员偏移量
 */
#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void) {
    printf("s 到 a 的偏移量 => %ld\n", offsetof(struct s, a));
    printf("s 中 a 成员大小 => %ld\n", sizeof(char));
    printf("s 到 b 的偏移量 => %ld\n", offsetof(struct s, b));
    printf("a 到 b 的空洞 => %ld\n", offsetof(struct s, b) - sizeof(char));
    printf("s 中 b 成员大小 => %ld\n", sizeof(int [2]));
    printf("s 到 c 的偏移量 => %ld\n", offsetof(struct s, c));
    printf("s 中 c 成员大小 => %ld\n", sizeof(float));
    printf("s 的大小 => %ld\n", sizeof(struct s));
    return 0;
}