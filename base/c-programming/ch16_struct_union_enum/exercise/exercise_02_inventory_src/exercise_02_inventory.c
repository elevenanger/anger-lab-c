/*
 * @author Anger
 * @date 2022/9/26
 * @brief 使得 print 函数可以按照零件编号的顺序显示零件
 */
#include <stdio.h>
#include "read_line.h"
#include "quick_sort.h"
#include "inventory.h"

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {

    char code;

    for(;;) {
        printf("i=>insert s=>search u=>update p=>print q=>quit\n");
        printf("ENTER OPERATION CODE : ");
        /* %c 前面的空格允许 scanf 在读入操作码之前忽略之前跳过的空白字符 */
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
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
        printf("\n");
    }
}

/**
 * 通过零件编号查找零件
 * @param number 零件编号
 * @return 仓库中存在该零件的零件编号
 */
int find_part(int number) {
    int i;
    for (i = 0; i < num_parts; ++i)
        if (inventory[i].number == number)
            return i;
    return -1;
}

/**
 * 插入元素
 */
void insert(void) {
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("inventory is full.\n");
        return;
    }

    printf("Enter part number : ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("part already exist.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter name : ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter on hand : ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(void) {
    int i, number;

    printf("Enter part number : ");
    scanf("%d", &number);

    i = find_part(number);

    if (i >= 0) {
        printf("part.name => %s\n", inventory[i].name);
        printf("quantity on hand => %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

void update(void) {
    int i, number, change;
    printf("Enter part number : ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand : ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found.\n");
}

void print(void) {
    int i;

    printf("Part Number Part Name                  "
           "Quantity on Hand\n");

    quick_sort(inventory, 0, num_parts - 1);

    for (i = 0; i < num_parts; i++)
        printf("%7d        %-25s%11d\n",
               inventory[i].number,
               inventory[i].name,
               inventory[i].on_hand);
}
