/*
 * @author Anger
 * @date 2022/10/13
 * @brief 括号栈实现
 */
#include "linked_list_queue.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *top;
};

Queue create_queue(void) {
    Queue queue = malloc(sizeof(struct queue_type));
    if (queue == NULL)
        exit(EXIT_FAILURE);

    queue->top = NULL;
    return queue;
}

void destroy_queue(Queue queue) {
    make_empty(queue);
    free(queue);
}

void make_empty(Queue queue) {
    while (!is_empty(queue))
        pop(queue);
}

bool is_empty(Queue queue) {
    return queue->top == NULL;
}

bool is_full(Queue queue) {
    return false;
}

void push(Queue queue, Item item) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        exit(EXIT_FAILURE);

    if (!is_bracket(item))
        return;

    new_node->data = item;
    new_node->next = queue->top;
    queue->top = new_node;
}

Item pop(Queue queue) {
    Item item;
    struct node *popped_node;

    if (is_empty(queue))
        exit(EXIT_FAILURE);

    popped_node = queue->top;
    item = popped_node->data;
    queue->top = popped_node->next;
    free(popped_node);

    return item;
}

bool is_bracket(Item item) {
    switch (item) {
        case '{': case '}': case '(': case ')':
            return true;
        default: return false;
    }
}