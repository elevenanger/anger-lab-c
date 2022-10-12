/*
 * @author Anger
 * @date 2022/10/12
 * @brief 将 Stack 进行抽象
 */
#include <stdbool.h>

#ifndef ANGER_LAB_C_TACK_H
#define ANGER_LAB_C_TACK_H
#define STACK_SIZE 100

/* 不完整类型
 * 描述了对象但是缺少定义对象大小所需要的信息
 * 这样可以在实现文件中对于具体的数据类型进行定义
 * 避免通过头文件暴露对象的底层细节 */
typedef struct stack_type *Stack;

/* 另一个数据类型的抽象
 * 栈里面的项都是整数
 * 比较局限
 * 事实上，栈中的数据类型应该是无关紧要的，可以是其它的数据类型
 * 为了使栈抽象数据类型更易于针对不同的数据项类型进行修改
 * 使用类型名 Item 表示存储到占中的数据的类型 */
typedef int Item;

/* create destroy 方法
 * 模块通常不需要这些方法
 * 但是抽象的数据类型需要
 * create 会为抽象的数据类型 -> 栈分配内存，同时把栈置为空
 * destroy 会释放栈动态分配的内存 */
Stack create(void);
void destroy(Stack stack);
void make_empty(Stack stack);
bool is_empty(Stack stack);
bool is_full(Stack stack);
void push(Stack stack, Item i);
Item pop(Stack stack);

#endif //ANGER_LAB_C_TACK_H
