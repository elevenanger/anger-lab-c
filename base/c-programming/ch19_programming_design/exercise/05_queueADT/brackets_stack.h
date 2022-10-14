/*
 * @author Anger
 * @date 2022/10/13
 * @brief 判断括号匹配
 */
#include <stdlib.h>
#include <stdbool.h>

#ifndef ANGER_LAB_C_BRACKETS_STACK_H
#define ANGER_LAB_C_BRACKETS_STACK_H
#define ITEM_SIZE 10

typedef char Item;

typedef struct queue_type *Queue;

Queue create_queue(void);
void destroy_queue(Queue queue);
void make_empty(Queue queue);
bool is_full(Queue queue);
bool is_empty(Queue queue);
void push(Queue queue, Item item);
Item pop(Queue queue);

bool is_bracket(Item item);

#endif //ANGER_LAB_C_BRACKETS_STACK_H
