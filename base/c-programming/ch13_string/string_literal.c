/*
 * @author Anger
 * @date 2022/9/15
 * @brief 字面串 用一对双引号引用起来的字符序列
 */
#include <stdio.h>

void continuation_literal(void);

void store_literal(void);

void manipulation_literal(void);

char digit_to_hex_char(int digit);

int main(void) {
    continuation_literal();
    store_literal();
    manipulation_literal();
    return 0;
}

/**
 * 延续字面串
 * 如果字面串太长无法放置在一行内
 * 只要把第一行的字面串以 \ 结尾
 * 就可以在下一行延续字面串
 * 除了看不到的末尾换行符
 * 同一行内不能有其它字符跟在 \ 后面
 * 使用 \ 有一个缺陷
 * 字面串必须在下一行的起始位置继续
 * 这就破坏了程序的缩进结构
 * 处理长字面串还有一种更好的方式
 * 就是两条或者多条字面串相邻时（仅用空白字符分割）
 * 编译器会把它们合并成一条字符串
 */
void continuation_literal(void) {
    /* 使用 \ 进行延续 */
    printf("this is first part of a long string \
this is second part..");
    /* 编译器自动将两条相邻的空白字符分割的字面串组成一条字符串 */
    printf("\nthis is first part of a long string "
           "this is second part...\n");
}

/**
 * 存储字面串
 * C 语言把字面串当做字符数组来处理
 * 当 C 语言编译器在程序中遇到长度为 n 的字面串时
 * 会为字面串分配 n+1 的内存空间
 * 这块内存空间用于存储字面串的字符以及一个标识字符串末尾的额外字符（空字符）
 * 空字符是一个所有位都为 0 的字符
 * 用转译序列 \0 类表示
 * 字面串可以为空， "" 用一个单独的空字符来存储
 * 既然字面串是作为数组来存储的，编译器会把它看做 char * 类型指针
 */
void store_literal(void) {
    char *s = "abcd\n";
    /*printf 函数使用 %s 格式化字符串*/
    printf("%s", s);
}

/**
 * 字面串操作
 * 通常情况下，可以在任意 C 语言允许使用 char *指针的地方使用字面串
 */
void manipulation_literal(void) {
    char *string;
    /* 字面串可以出现在赋值运算符的右边 */
    string = "hello";
    char ch;
    /* C 语言允许对于指针取下标，因此可以对字面串取下标 */
    ch = string[1];
    printf("ch => %c\n", ch);

    printf("15 => %c\n", digit_to_hex_char(15));
}

/**
 * 将数字转换成 16 进制形式字符
 * @param digit 数字
 * @return 对应十六进制字符
 */
char digit_to_hex_char(int digit) {
    return "01234567890ABCDEF"[digit];
}