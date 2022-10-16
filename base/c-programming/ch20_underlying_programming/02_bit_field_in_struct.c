/*
 * @author Anger
 * @date 2022/10/16
 * @brief 结构中的位域
 */
#include <stdio.h>

/**
 * 结构中的位域
 * 结构中的每个成员的后面的数值指定了它所占用位的长度
 * 位域的类型必须是 int |unsigned int | signed int
 * 将所有的位域声明为 unsigned int 或者 signed int 会具备更强的可移植性
 * 从 C99 开始，位域也可以使用 _Bool 类型或者其它额外的类型
 */
struct file_date {
    unsigned int day:5, month:4, year:7;
    _Bool leap_year_flag:1;
};

void use_bit_field(void);

int main(void) {

}

void use_bit_field(void) {
    /* 可以像结构中的其它成员一样使用位域 */
    struct file_date fd;
    fd.day = 20;
    fd.month = 10;
    fd.year = 120;
    /* 不能使用取地址运算符访问位域
     * 因为位域没有地址 */
//    scanf("%d", &fd.year);
}
