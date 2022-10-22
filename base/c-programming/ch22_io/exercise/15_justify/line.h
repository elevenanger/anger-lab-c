/*
 * @author Anger
 * @date 2022/9/22
 * @brief 对行进行操作
 */

#ifndef ANGER_LAB_C_LINE_H
#define ANGER_LAB_C_LINE_H
/* 清除当前行的内容 */
void clear_line(void);
/* 往当前行的末尾添加单词
 * 如果这个单词不是第一个单词，需要在此之前添加一个空格 */
void add_word(const char *word);
/* 检查当前行剩余的空间 */
int space_remaining(void);
/* 写入调整过的当前的行 */
void write_line(FILE *fp);
/* 不调整写入当前行，如果当前行为空则什么都不做 */
void flush_line(FILE *fp);
#endif //ANGER_LAB_C_LINE_H