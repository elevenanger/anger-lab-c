/*
 * @author Anger
 * @date 2022/9/24
 * @brief 嵌套的结构
 */
#include <string.h>
#define FIRST_NAME_LEN 20
#define LAST_NAME_LEN 25

void struct_array(void);

/* 在结构中嵌套数组 */
struct person_name {
    char first[FIRST_NAME_LEN + 1];
    char middle_initial;
    char last[LAST_NAME_LEN + 1];
};

/* 在结构中嵌套结构 */
struct student {
    struct person_name name;
    int id, age;
    char sex;
};


int main(void) {
    return 0;
}

void struct_array(void) {
    /* 初始化结构数组
     * 数组的花括号里面
     * 每个结构都以花括号括起来*/
    struct student outstanding_students[] = {
            {.name.first = "Paul\0", .name.middle_initial = 'C', .name.last = "Pierce\0",
                .age = 10, .id = 1, .sex = 'F'},
            {.name.first = "Wong\0", .name.middle_initial = 'P', .name.last = "Qin\0",
                .age = 11, .id = 13, .sex = 'M'},
                /* C99 结构数组的初始化器和指示器联合起来使用 */
            [2].name.first = "Gang\0"};

    struct student class_1[30];

    /* 访问结构数组中的元素 */
    strcpy(class_1[0].name.first, "Song\0");
}
