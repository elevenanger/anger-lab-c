/*
 * @author Anger
 * @date 2022/10/16
 * @brief 其它底层技术
 */
#include <stdio.h>

/* 定义依赖机器的类型
 * char 类型占据一个字节
 * 可以使用其来存储一些不一定是字符形式的数据 */
typedef unsigned char BYTE;
/* x86 体系结构使用了大量的 16 位的字 */
typedef unsigned short WORD;

struct file_date {
    /* 7+4+5 = 16
     * file_date 结构占据两个字节的空间 */
    unsigned int year:7, month:4, day:5;
};

union int_date {
    /* short 占据两个字节的空间
     * 通过 union 提供数据的多个视角
     * 通过这个联合
     * 可以以两个字节的形式获取存储的日期
     * 然后提取其中的 month day year 字段的值
     * 也可以以 file_date 结构构造一个日期
     * 然后作为两个字节存储 */
    unsigned short i;
    struct file_date date;
};

/* 使用多个视角实现寄存器 */
union {
    /* 16 位寄存器
     * 每个寄存器都可以看成两个 8 位寄存器
     * ax 可以划分为 低位 al 高位 ah 两个寄存器 */
    struct {
        WORD ax, bx, cx, dx;
    } word;
    /* 8 位寄存器 */
    struct {
        BYTE al, ah, bl, bh, cl, ch, dx, dh;
    } byte;
} regs;

void multiple_perspective_of_data_by_union(unsigned short i);
void register_implement(void);
void pointer_as_address(void);
/* 查看内存单元 */
void view_memory(void);
void volatile_type_qualifier(void);

int main(void) {

    multiple_perspective_of_data_by_union(200);

    register_implement();

    pointer_as_address();

    return 0;
}

void multiple_perspective_of_data_by_union(unsigned short i) {
    printf("使用联合提供数据的多个视角 => %s\n", __FUNCTION__);

    union int_date u;

    u.i = i;
    printf("%d/%d/%d\n",
           u.date.month, u.date.day, u.date.year + 1980);
}

void register_implement(void) {
    printf("使用联合实现寄存器的多个视角 => %s\n", __FUNCTION__ );
    regs.byte.ah = 0x12;
    regs.byte.al = 0x34;
    printf("ax = %hx\n", regs.word.ax);
}

void pointer_as_address(void) {
    printf("将指针作为地址使用 => %s\n", __FUNCTION__ );
    BYTE *p;
    /* 构造一个指针存储内存地址 */
    p = (BYTE *) 0x1000;
    view_memory();
}

void view_memory(void) {
    unsigned int addr;
    printf("main 函数的地址：%lx\n", (unsigned long) main);
    printf("addr 变量的地址：%lx\n", (unsigned long) &addr);
}

void volatile_type_qualifier(void) {
    printf("volatile 类型限定符 => %s\n", __FUNCTION__);
    /* volatile 类型限定符通知编译器，程序中的某些数据是易变的
     * volatile 类型限定符会通知编译器 *p 每次都必须要从内存中重新取值 */
    volatile BYTE *p;
}
