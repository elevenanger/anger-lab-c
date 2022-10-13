/*
 * @author Anger
 * @date 2022/10/12
 * @brief 将 Stack 进行抽象
 */
#include <stdbool.h>

#ifndef ANGER_LAB_C_TACK_H
#define ANGER_LAB_C_TACK_H
#define STACK_SIZE 100

typedef struct stack_type *Stack;

typedef int Item;

Stack create(int size);
void destroy(Stack stack);
void make_empty(Stack stack);
bool is_empty(Stack stack);
bool is_full(Stack stack);
void push(Stack stack, Item i);
Item pop(Stack stack);

#endif //ANGER_LAB_C_TACK_H
