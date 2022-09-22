/*
 * @author Anger
 * @date 2022/9/22
 * @brief 结构变量
 */
#include <stdio.h>

#define NAME_LEN 20

/* 这里定义的每个结构都有三个成员
 * number name on_hand
 * part1 和 part2 是具有这种类型的变量
 * 结构的成员在内存中是按照顺序存储的
 * 每个结构代表一种新的作用域
 * 任何声明在此作用域的名字都不会和程序中的其它名字冲突
 * 每个结构都为它的成员设置了独立的名字空间 (namespace)
 * 结构标记用于标记某种特定结构的名字
 * 这里将结构名字标记为 part */
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
}  part_1 = {100, "shot_gun", 20},
    /* 结构的初始化器
     * 初始化器中的值必须按照结构的顺序来显示
     * 用于结构的初始化器必须是常量 */
    part_2 = {200, "mav", 10},
    /* 使用点表示法进行结构的初始化(指示器) */
    part_3 = {.name = "fire_maker", .number = 100, .on_hand = 2},
    part_4 = {};

void struct_operation(void);
void declare_struct_variable(void);

int main(void) {

    struct_operation();

    declare_struct_variable();

    return 0;
}

void struct_operation(void) {
    /* part_1.name 访问结构的成员 */
    printf("part_%d.name => %s\n", 1, part_1.name);

    /* 对结构中的成员进行赋值和自增操作 */
    part_2.on_hand = 30;
    part_2.number++;
    printf("part_2.on_hand => %d\n", part_2.on_hand);
    printf("part_2.number => %d\n", part_2.number);

    /* .运算符的优先级高于 & 运算符*/
    scanf("%d", &part_4.number);
    printf("part_4.number => %d\n", part_4.number);

    /* 赋值运算，将 part_3 结构的所有成员复制到 part_4
     * 嵌套在结构中的数据结构也会被复制
     * 包括数组 */
    part_4 = part_3;
    printf("part_4.name => %s\n", part_4.name);
}

void declare_struct_variable(void) {
    /* 一旦创建了结构标记
     * 就可以通过它来声明变量
     * struct tag_name variable
     * part 不是类型名
     * 如果没有 struct 关键字，它就没有任何意义 */
    struct part part_5 = {.number = 100, .name = "Five", .on_hand = 5};
    printf("part_5.name => %s\n", part_5.name);
}
