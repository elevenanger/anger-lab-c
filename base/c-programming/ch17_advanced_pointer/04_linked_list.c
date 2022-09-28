/*
 * 链表
 * 链表是由一连串的结构（节点）组成的
 * 每一个节点都包含指向下一个节点的指针
 * 链表最后一个节点包含一个空指针
 * 相对于数组
 * 链表可以根据需要进行放大或者缩小
 * 但是也失去了数组的随机访问能力
 * 可以用相同的时间访问数组中的任意元素
 * 但是访问链表则不然
 * 越靠近起点位置的元素访问速度越快
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;          /* 存储在节点中的数据 */
    struct node *next;  /* 指向下一个节点的指针 */
};

void first_node(void);
void create_node(void);
void right_arrow_operator(void);
void insert_node(void);
struct node* add_to_list(struct node *list, int n);
struct node* read_number(struct node *list);
void print_list(struct node *list);
struct node* search_list(struct node *list, int n);
struct node * delete_node_from_list(struct node *list, int n);


int main(void) {

    int searched_node, delete_node;

    struct node *first = NULL;

    first = read_number(first);

    print_list(first);

    printf("Enter node to search : ");
    scanf(" %d", &searched_node);
    struct node *n = search_list(first, searched_node);
    printf("%d\n", n->value);

    printf("Enter node to delete : ");
    scanf(" %d", &delete_node);
    delete_node_from_list(first, delete_node);
    print_list(first);

    return 0;
}

/**
 * 记录链表的初始节点
 */
void first_node(void) {
    /* 记录链表开始的位置
     * 指向表中第一个节点的变量
     * 把 first 初始化为 NULL */
    struct node *first = NULL;
}

/**
 * 创建节点
 * 1、为节点分配内存单元
 * 2、把数据存储到节点中
 * 3、把节点插入到链表中
 */
void create_node(void) {
    struct node *node_0;
    node_0 = malloc(sizeof(struct node));
    (*node_0).value = 0;
}

/**
 * 右箭头运算符
 * 使用指针访问结构中的成员是很普遍的
 * c 语言为此专门提供了一种运算符
 * 此运算符称为右箭头选择运算符
 */
void right_arrow_operator(void) {
    struct node *node_0 = malloc(sizeof(struct node));
    node_0->value = 10; /* 使用右箭头运算符访问结构指针中的成员 */
}

/**
 * 在链表中插入节点
 */
void insert_node(void) {
    /* 将 first 节点置位 空指针 */
    struct node *new_node, *first = NULL;
    /* 为了 new_node 分配内存空间 */
    new_node = malloc(sizeof(struct node));
    /* new_node 成员进行赋值 */
    new_node->value = 10;
    /* new_node next 指向 first_node */
    new_node->next = first;
    /* 使 first 指向新节点 */
    first = new_node;

    /* 再网链表中插入一个新节点
     * 使用这种方式可不断往链表中插入节点
     * 新增节点不会修改原来的指针
     * 而是将链表指向新增的节点(现在链表的最开始处) */
    new_node = malloc(sizeof(struct node));
    new_node->value = 20;
    new_node->next = first;
    first = new_node;
}

/**
 * 往链表中插入结点
 * @param list 链表
 * @param n 需要存储在新节点中的数据
 * @return 已经插入元素的链表
 */
struct node* add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error : malloc failed in %s list\n", __FUNCTION__ );
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    list = new_node;
    return list;
}

struct node* read_number(struct node *list) {
    int number;
    printf("Enter series of integers (0 to terminate) : ");
    for (;;) {
        scanf("%d", &number);
        if (number == 0)
            return list;
        list = add_to_list(list, number);
    }
}

void print_list(struct node *list) {
    do {
        printf("%d ", list->value);
    } while ((list = list->next) != NULL);

    puts("");
}

/**
 * 搜索链表
 * @param list 链表
 * @param n 存储在节点中的数据
 * @return 存储数据的节点
 */
struct node* search_list(struct node *list, int n) {
    struct node *p;
    /* 惯用的遍历链表的形式 */
    for (p = list; p != NULL; p = p->next)
        if (p->value == n)
            return p;
    return NULL;
}

/**
 * 从链表中删除节点
 * @param list 链表
 * @param n 存储在节点中的数据
 * @return 被删除的节点
 * 1、定位要删除的节点
 * 2、改变前一个节点，从而使它绕过删除节点
 * 3、调用 free 函数回收删除节点占用的内存空间
 */
struct node * delete_node_from_list(struct node *list, int n) {
    struct node *prev, *cur;
    /* 使用追踪指针的方法定位要删除的节点以及前一个节点 */
    for (prev = NULL, cur = list;       /* 两个指针，一个指向当前的节点，一个指向前一个节点 */
        cur != NULL && cur->value != n; /* 当前指针不为 NULL 并且当前指针指向的数据不匹配n则继续*/
        prev = cur, cur = cur->next);   /* prev 指向当前节点，当前指针指向下一个节点 */
    /* 找不到要删除的节点，直接返回原list */
    if (cur == NULL)
        return list;
    /* 如果前一个指针为空指针，说明 n 对应链表中第一个节点
     * 将链表指针后移一位 */
    if (prev == NULL)
        list = list->next;
    /* 如果 prev 不为空
     * n 对应链表中的其它节点
     * 将 prev next 指向 cur next 节点 */
    else
        prev->next = cur->next;
    /* 释放 cur 节点，返回链表 */
    free(cur);
    return list;
}
