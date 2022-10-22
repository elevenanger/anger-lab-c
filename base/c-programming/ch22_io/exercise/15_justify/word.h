/*
 * @author Anger
 * @date 2022/9/22
 * @brief 单词读取头文件
 */
/* 使用下面这种方式防止多次包含 word.h 文件 */
#ifndef ANGER_LAB_C_WORD_H
#define ANGER_LAB_C_WORD_H
/**
 * 从输入中读取下一个单词，并将其存储在 word 变量中
 * 当没有单词可读取的时候将 word 值置为空
 * 当单词的长度达到达到最大长度时截断单词
 * @param word
 * @param len
 */
int read_word(char *word, int len, FILE *fp);
#endif
