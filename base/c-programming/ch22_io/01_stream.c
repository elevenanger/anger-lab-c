/*
 * @author Anger
 * @date 2022/10/16
 * @brief 流 表示任意输入的源或者输出的目的地
 */
#include <stdio.h>

/* 文件指针 */
void file_pointer(void);
/* c 语言中的标准流 */
void standard_stream(void);
/* 文本文件和二进制文件 */
void text_file_and_binary_file(void);

int main(void) {
    return 0;
}

void file_pointer(void) {
    /* c 语言中对流的访问是通过文件指针实现的
     * */
    FILE *fp;
}

void standard_stream(void) {
    /* <stdio.h> 中提供了三个标准流
     * stdin 标准输入 键盘
     * stdout 标准输出 屏幕
     * stderr 标准错误 屏幕 */
}

void text_file_and_binary_file(void) {
    /* <stdio.h> 支持文本文件和二进制文件：
     * 文本文件 字节表示字符
     * 二进制文件 字节不一定表示字符，还可以表示其他类型的数据
     * 文本文件分为若干行，文本文件的每行通常都以一两个特殊字符结尾
     * 文本文件可以包含一个特殊的"文件末尾"标记
     * 二进制文件不分行，也没有行尾标记和文件末尾标记
     * 所有的字节都是平等的
     * 向文件写入数据时，需要考虑是按照文本格式存储还是二进制形式存储
     * 考虑在文件存储数的情况，一种选择是将数按照字符逐个写入
     * 如果字符集是 ASCII 则一个字符一个字节
     * 如果是以二进制的形式存储
     * 则会占用数值对应的二进制大小的字节
     * 使用二进制可以节省较大的空间 */
}
