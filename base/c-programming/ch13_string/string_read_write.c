/*
 * @author Anger
 * @date 2022/9/15
 * @brief 读写字符串
 */
#include <stdio.h>

void write_string_by_printf(void);
void write_string_by_puts(void);
void read_string_by_scanf(void);
int read_line(char str[], int n);
void test_read_line(void);

int main(void) {
    write_string_by_printf();
    write_string_by_puts();
    test_read_line();
    return 0;
}

/**
 * 使用 printf() 函数写字符串
 */
void write_string_by_printf(void) {
    char *string = "Today is Sep 15.";
    /* 使用 %s 允许 printf() 函数写字符串
     * 遇到空字符会停止 */
    printf("%s\n", string);
    /* %.ns n是要显示的字符数量 */
    printf("%.5s\n", string);
    /* %m.ns m 是字符显示的位数
     * 默认右对齐
     * 左对齐在 m 前面加上一个负号
     * 如果超过 m 个字符会显示整个字符串不会截断*/
    printf("%10.5s\n", string);
    printf("%-10.5s\n", string);
    printf("%2.5s\n", string);
}

/**
 * 使用 puts 函数写字符串
 */
void write_string_by_puts(void) {
    char *string = "Today is Sep 15.";
    /* puts 函数只接收一个参数就是要显示的字符串
     * 写完字符串后 puts 函数会自动添加一个换行符*/
    puts(string);
}

void read_string_by_scanf(void) {
    char string[80];
    printf("Enter a string :");
    /* 使用转换说明 %s 将字符串读入字符数组
     * scanf 函数会在字符串的末尾存储一个空字符 */
    scanf("%s", string);
    printf("string => %s\n", string);
}

/**
 * 自定义字符串读取方法
 * 需要注意的点：
 * 1、开始存储字符之前是否需要跳过空白字符
 * 2、什么字符会导致函数停止读取
 * 3、如果输入的字符过长，函数应该做什么，忽略额外的字符还是把它们留给下一次的操作
 * @param str 字符串
 * @param n 读入最大字符数
 */
int read_line(char str[], int n) {
    int ch, i = 0;
    /* 遇到换行符则停止读取
     * EOF 表示读取到文件末尾或者错误不能继续读取字符 */
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
    /* 终止字符 */
    str[i] = '\0';
    /* 存储的字符数量 */
    return i;
}

void test_read_line(void) {
    int i = 20, count;
    char str[i];
    printf("Read line: ");
    count = read_line(str, i);
    printf("read character number => %d\n", count);
    printf("%s", str);
}
