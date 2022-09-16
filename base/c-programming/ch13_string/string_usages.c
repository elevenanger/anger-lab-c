/*
 * @author Anger
 * @date 2022/9/16
 * @brief 字符串的惯用法
 */
#include <stdio.h>

/* 搜索字符串结尾的空白字符 */
size_t my_str_len_for_ver(const char *string);
size_t my_str_len_while_ver(const char *string);
size_t my_str_len_pointer_arithmetic_ver(const char *string);
/* 复制字符串 */
char *my_str_cat(char *dest, const char *string);
char *my_str_cat_simple_ver(char *dest, const char *string);


int main(void) {
    char s[20] = "string";
    printf("str len for  => %ld\n", my_str_len_for_ver(s));
    printf("str len while => %ld\n", my_str_len_while_ver(s));
    printf("str len pointer arithmetic => %ld\n", my_str_len_pointer_arithmetic_ver(s));

    printf("str cat => %s\n", my_str_cat(s, "_cat1"));
    printf("str cat => %s\n", my_str_cat_simple_ver(s, "_cat2"));
    return 0;
}

/**
 * 很多操作都需要搜索字符串的结尾
 * strlen 获取字符串的长度就是
 * 读取到空白字符则停止
 * @param string 需要计算长度的字符串
 * @return 字符串的长度
 */
size_t my_str_len_for_ver(const char *string) {
    size_t n;
    /* 取字符指针自增的值
     * 因为空白字符的整数值就是 0
     * 所以当指针指向空白字符即结束
     * 在循环中对计数 n 进行自增即可以获得字符串的长度 */
    for (n = 0;*string++; n++);
    return n;
}

/**
 * 使用 while 循环获取字符串的长度
 * @param string 需要计算长度的字符串
 * @return 字符串的长度
 */
size_t my_str_len_while_ver(const char *string) {
    size_t n = 0;
    while (*string++)
        n++;
    return n;
}

/**
 * 通过指针算数运算计算字符串的长度
 */
size_t my_str_len_pointer_arithmetic_ver(const char *string) {
    /* 字符串指针指向字符串的初始位置 */
    const char *p = string;
    /* 对原字符串指针进行自增操作，直到空白字符 */
    while (*string)
        string++;
    /* 返回两个指针的差值 */
    return string - p;
}

/**
 * 拼接字符串
 * @param dest 目标字符串
 * @param string 源字符串
 * @return 拼接后的字符串
 */
char *my_str_cat(char *dest, const char *string) {
    char *p = dest;
    /* 确定目标字符串结尾的位置 */
    while (*p != '\0')
        p++;
    /* 将需要拼接的字符串指针移动至字符串末尾位置
     * 每一位都复制到目标字符串 */
    while (*string != '\0')
        *p++ = *string++;
    /* 拼接空白字符串标识为字符串末尾 */
    *p = '\0';
    /* 返回目标字符串 */
    return dest;
}

char *my_str_cat_simple_ver(char *dest, const char *string) {
    char *p = dest;
    while (*p)
        p++;
    /* 字符串复制
     * **p++ = *string++ 赋值表达式的值是复制的字符
     * 也就是复制的字符不为空白字符即为真
     * 复制的字符为空白字符即为假
     * 复制到空白字符即终止
     * 因为循环在赋值后终止
     * 所以无需额外拼接空白字符 */
    while ((*p++ = *string++));
    return dest;
}
