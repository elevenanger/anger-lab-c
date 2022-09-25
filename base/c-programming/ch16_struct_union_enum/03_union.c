/*
 * @author Anger
 * @date 2022/9/25
 * @brief 联合
 * 联合和结构一样是由一个或者多个成员构成
 * 每个成员可以是不同的类型
 * 编译器只会为联合中最大的成员分配内存空间
 * 联合的成员在这个空间内彼此覆盖
 * 给一个成员赋值会改变其它成员的值
 */
#include <stdio.h>

#define INT_KIND 0
#define FLOAT_KIND 1

/* 结构和联合的唯一不同之处在于 ：
 * 结构的所有成员存储在不同的内存地址中
 * 联合的所有成员存储在相同的内存地址中 */
union u {
    int i;
    float f;
}   u1 = {0},
    /* 联合只能初始化一个成员，单不一定需要是第一个 */
    u2 = {.f = 10.2f};

typedef struct {
    /* 使用 kind 来表示 union 的哪个字段被赋值 */
    int kind;
    union u u;
} s;

typedef union {
    int i;
    /* 匿名 union */
    union {char c; float f;};
} anonymous_union_u;

typedef struct {
    int i;
    union {char c; float f;};
} anonymous_union_s;

void create_compound_data_structure(void);
void tagged_union(void);
void print_tagged_union_s(s s);
void anonymous_union(void);

int main(void) {
    tagged_union();
    return 0;
}

/**
 * 使用 union 来创建混合的数据结构
 */
void create_compound_data_structure(void) {
    union u u_arr[2] = {{0}, {.f = 10.2f}};
}

/**
 * 为 union 添加标记字段
 */
void tagged_union(void) {
    s s1;
    s1.kind = INT_KIND;
    s1.u.i = 10;

    s s2;
    s2.kind = FLOAT_KIND;
    s2.u.f = 10.1f;

    print_tagged_union_s(s1);
    print_tagged_union_s(s2);
}

void print_tagged_union_s(s s) {
    if (s.kind)
        printf("s.u.f => %g\n", s.u.f);
    else
        printf("s.u.i => %d\n", s.u.i);
}

/**
 * C1X 特性
 * 匿名 union
 */
void anonymous_union(void) {
    /* 若某个匿名 union un
     * 是另一个 union u 的成员
     * 则匿名 un 的成员被视为 u 的成员 */
    anonymous_union_s s;
    anonymous_union_u u;
    s.c = 'c';
    u.c = 'c';
}
