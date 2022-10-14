/*
 * @author Anger
 * @date 2022/10/13
 * @brief 括号栈实现
 */
#include "brackets_stack.h"

struct queue_type {
    int top;
    Item items[ITEM_SIZE];
};

Queue create_queue(void) {
    Queue queue = malloc(sizeof(struct queue_type));
    queue->top = 0;
    return queue;
}

void destroy_queue(Queue queue) {
    free(queue);
}

void make_empty(Queue queue) {
    queue->top = 0;
}

bool is_empty(Queue queue) {
    return queue->top == 0;
}

bool is_full(Queue queue) {
    return queue->top == ITEM_SIZE;
}

void push(Queue queue, Item item) {
    if (!is_bracket(item))
        return;

    if (is_full(queue))
        exit(EXIT_FAILURE);

    queue->items[queue->top++] = item;
}

Item pop(Queue queue) {
    if (is_empty(queue))
        exit(EXIT_FAILURE);

    return queue->items[--queue->top];
}

bool is_bracket(Item item) {
    switch (item) {
        case '{': case '}': case '(': case ')':
            return true;
        default: return false;
    }
}