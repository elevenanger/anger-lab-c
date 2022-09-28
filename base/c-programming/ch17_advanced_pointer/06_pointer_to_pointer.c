/*
 * @author Anger
 * @date 2022/9/28
 * @brief 指向指针的指针
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int i;
    struct node *next;
};

void add_to_list(struct node **list, int n);

int main(void) {
    return 0;
}

/**
 * 往链表中添加节点
 * @param list 指向链表的指针的指针
 * @param n 存储在节点中的数据
 */
void add_to_list(struct node **list, int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));

    if (new_node ==NULL) {
        printf("Error malloc failed in %s\n", __FUNCTION__ );
        exit(EXIT_FAILURE);
    }

    new_node->i = n;
    new_node->next = *list;
    /* 将新节点赋值给指向链表的指针 */
    *list = new_node;
}
