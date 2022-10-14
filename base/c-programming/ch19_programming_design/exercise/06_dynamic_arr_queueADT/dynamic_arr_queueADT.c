/*
 * @author Anger
 * @date 2022/10/13
 * @brief 括号栈实现
 */
#include "dynamic_arr_queue.h"

struct queue_type {
    int size;
    int top;
    Item *items;
};

Queue create_queue(int size) {
    Queue queue = malloc(sizeof(struct queue_type));
    if (queue == NULL)
        exit(EXIT_FAILURE);

    queue->items = malloc(size * sizeof(Item));
    if (queue->items == NULL)
        exit(EXIT_FAILURE);

    queue->size = size;
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
    return queue->top == queue->size;
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