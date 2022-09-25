/*
 * @author Anger
 * @date 2022/9/25
 * @brief 枚举
 */
#include <stdio.h>

/* 枚举类型是一种值由程序员列出的类型
 * 而且程序员必须为每个值命名（枚举常量）
 * 枚举常量的名字必须不同于作用域范围内的其它标识符
 * 枚举可以通过声明标记法
 * 或者 typedef 来创建独一无二的类型名 */
typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} Suit;

typedef struct {
    enum {INT_KIND, FLOAT_KIND} kind;
    union {
         int i;
         float f;
    } u;
} Number;

void declare_enum_variable(void);
void enum_as_integer(void);
void enum_tag_field(void);
void print_number(Number number);

int main(void) {
    enum_as_integer();
    enum_tag_field();
    return 0;
}

/**
 * 声明枚举类型变量
 */
void declare_enum_variable(void) {
    Suit suit_1, suit_2, suit_3;
    suit_1 = SPADES;
    suit_2 = HEARTS;
    suit_3 = CLUBS;
}

/**
 * 枚举作为整数
 * C 语言中，会将枚举变量和枚举常量作为整数来处理
 * 默认情况下，编译器会把整数赋值给特定枚举类型中的常量
 * 在没有为枚举常量指定值时，它的值比前一个常量的值大 1
 */
void enum_as_integer(void) {
    int i = DIAMONDS;
    printf("i = DIAMONDS => %d\n", i);
}

/**
 * 使用枚举标记字段
 */
void enum_tag_field(void) {
    Number number_i, number_f;
    number_i.kind = INT_KIND;
    number_i.u.i = 100;

    number_f.kind = FLOAT_KIND;
    number_f.u.f = 100.1f;
    print_number(number_i);
    print_number(number_f);
}

void print_number(Number number) {
    if (number.kind == INT_KIND)
        printf("number.u.i => %d\n", number.u.i);
    else
        printf("number.u.f => %g\n", number.u.f);
}
