/*
 * @author Anger
 * @date 2022/9/2
 * @brief 字符操作
 */
#include <stdio.h>
#include <ctype.h>

/**
 * 在 c 语言中字符当做小整数来处理
 * 字符常量实际上是 int 类型而不是 char 类型
 * 计算中出现字符时， c 语言只是使用它的整数值
 * 在 ASCII 码中 字符的取值范围为 00000000-11111111
 * 可以看成 0-127 的整数
 * 'a' 的值是 97
 * 'A' 的值是 65
 */
void char_literal() {
    char ch;
    int i;
    i = 65;
    ch = 'A';

    /*
     * 可以像比较数一样对字符进行比较
     */
    while (i < 'z') {
        printf("%d ", i++);
        printf("%d ", ch++);
    }

    puts("");
}

/**
 * c 语言中，一些特殊的符号是无法使用正常的方式书写的
 * 因为它们不可见
 * 或者无法从键盘输入
 * 为了是程序能够处理字符集中的每一个字符
 * c 语言提供了一种特殊的表示方法-转义序列
 * 转义序列有两种
 * 一种是字符转义序列
 * 一种是数字转义序列
 */
void escape_sequence() {
    printf("\\a : \a 响铃符\n");
    printf("\\b : \b 回退符\n");
    printf("\\f : \f 换页符\n");
    printf("\\n : \n 换行符\n");
    printf("\\r : \r 回车符\n");
    printf("\\t : \t 水平制表符\n");
    printf("\\v : \v 垂直制表符\n");
    printf("\\ : \\ 反斜杠\n");
    printf("\\? : ? 问号\n");
    printf("\\' : ' 单引号\n");
    printf("\" : 双引号\n");
}

/*
 * 使用 ctype 标准库中的方法对字符进行处理
 */
void process_char() {
    char ch = 'A';
    while (ch <= 'Z')
        printf("%c ", tolower(ch++));

    while (ch <= 'z')
        printf("%c ", toupper(ch++));

    puts("");
}

/**
 * 使用 scanf 和 printf 函数读写字符
 * %c 表示字符类型
 */
void read_and_write_char() {
    char ch1, ch2;
    printf("Enter two character : ");
    /*
     * scanf 函数读取字符类型时
     * 不会跳过空白字符
     * 如果需要读取的过程中跳过字符前的空白字符
     * 需要在格式串中的转换说明 %c 之前加上一个空格
     */
    scanf("%c %c", &ch1, &ch2);
    printf("Upper case : %c %c\n", toupper(ch1), toupper(ch2));
}

/**
 * 使用 getchar() 和 putchar() 读写字符
 * 用于读写单个字符
 */
void put_get_char() {
    /*
     * getchar() 返回一个 int 类型值
     * getChar() 也不能在读取时跳过空白字符
     * getchar() 和 putchar() 的效率比 scanf() 和 printf() 快得多
     * 一个原因是其简单，因为只用来读写字符类型的值
     * 另一个原因是为了额外的速度提升
     * 作为宏来实现
     */
    int len = 0;
    char ch;

    printf("Enter a message : ");
    while ((ch = getchar()) != '\n') {
        putchar(ch);
        putchar(' ');
        len++;
    }

    printf("\nMessage length : %d\n", len);
}


int main(void) {

    char_literal();

    escape_sequence();

    process_char();

    put_get_char();

    return 0;
}