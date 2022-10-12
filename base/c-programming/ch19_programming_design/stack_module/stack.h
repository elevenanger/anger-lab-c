/*
 * @author Anger
 * @date 2022/10/12
 * @brief  
 */

#ifndef ANGER_LAB_C_STACK_H
#define ANGER_LAB_C_STACK_H

#include <stdbool.h>

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif //ANGER_LAB_C_STACK_H
