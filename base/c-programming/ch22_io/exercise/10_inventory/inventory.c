/*
 * @author Anger
 * @date 2022/9/28
 * @brief 使用有序链表重构 inventory 程序
 * 使用链表替代数组的好处在于
 * 1、不需要事先限制数据库的大小
 * 2、可以很容易对零件编号进行排序,添加新的元素只需要插入到链表中合适的位置即可
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"

#define NAME_LEN 4

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main(void) {
    char code;

    for (;;) {
        printf("i => insert u => update s => search u => update p => print q => quit\n"
               "d => dump   r => restore\n");
        printf("Enter operation code : ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'd':
                dump();
                break;
            case 'r':
                restore();
                break;
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        puts("");
    }
}

struct part *find_part(int number) {
    struct part *p;
    /* 遍历链表，查找是否存在与 number 相等的节点
     * 因为是有序链表，所以当 number 的值 不大于节点中 number 的值则结束循环*/
    for (p = inventory;
        p != NULL && number > p->number;
        p = p->next);

    /* 如果 p 不为空指针并且 number 的值和 p 指向节点的 number 值相同
     * 则说明当前节点就是需要查找的节点 */
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void) {
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));

    if (new_node == NULL) {
        printf("Database is full.\n");
    }

    printf("Enter part number : ");
    scanf(" %d", &new_node->number);

    /* 找到新节点所在位置 */
    for (cur = inventory, prev = NULL;
            cur != NULL && new_node->number > cur->number;
            prev = cur, cur = cur->next);

    /* 如果 number 已存在则释放 new_node 返回 */
    if (cur != NULL && new_node->number == cur->number) {
        printf("part already exist.\n");
        free(new_node);
        return;
    }

    printf("Enter part name : ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand : ");
    scanf("%d", &new_node->on_hand);

    /* 将 new_node 下一个节点指向 cur 节点 */
    new_node->next = cur;
    /* 如果 prev 节点不为空，则将 prev 的下一个节点指向 new_node
     * 为空则说明 new_node 为开始节点
     * 链表的初始节点指向 new_node */
    if (prev != NULL)
        prev->next = new_node;
    else
        inventory = new_node;
}

void search(void) {
    int number;
    struct part *p;

    printf("%s Enter number : ", __FUNCTION__ );
    scanf("%d", &number);

    p = find_part(number);

    if (p != NULL)
        printf("Part name => %s\n"
               "Quantity on hand => %d\n",
               p->name, p->on_hand);
    else
        printf("Part not found.\n");
}

void update(void) {
    int number, change;
    struct part *part;

    printf("%s enter number : ", __FUNCTION__ );
    scanf("%d", &number);

    part = find_part(number);
    if (part != NULL) {
        printf("%s enter change in quantity on hand : ", __FUNCTION__ );
        scanf("%d", &change);
        part->on_hand += change;
    } else
        printf("%s part not found.\n", __FUNCTION__ );
}

void print(void) {
    struct part *part;
    printf("Part Number  Part Name  Quantity\n");
    for (part = inventory; part != NULL; part = part->next)
        printf("%8d      %4s        %4d\n",
               part->number, part->name, part->on_hand);
}

void dump(void) {
    FILE *out_file;
    char file_name[20];
    struct part *part;

    printf("Enter name of output file : ");
    read_line(file_name, 20);

    if ((out_file = fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "%s 无法打开\n", file_name);
        exit(EXIT_FAILURE);
    }

    for (part = inventory; part != NULL; part = part->next)
        fwrite(part, sizeof(struct part) - sizeof(struct part *), 1, out_file);

    fclose(out_file);
}

void restore(void) {
    FILE *in_file;
    char file_name[20];
    struct part buffer, *tmp, **pp;

    printf("Enter name of input file : ");
    read_line(file_name, 20);

    if ((in_file = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "%s 无法打开\n", file_name);
        exit(EXIT_FAILURE);
    }

    while (inventory != NULL) {
        tmp = inventory;
        inventory = inventory->next;
        free(tmp);
    }

    pp = &inventory;

    while (fread(&buffer, sizeof(struct part) - sizeof(struct part *), 1, in_file) == 1) {
        if ((*pp = malloc(sizeof(struct part))) == NULL) {
            fprintf(stderr, "内存分配失败\n");
        }
        (*pp)->number = buffer.number;
        (*pp)->on_hand = buffer.on_hand;
        strcpy((*pp)->name, buffer.name);
        (*pp)->next = NULL;
        pp = &(*pp)->next;
    }

    fclose(in_file);
}