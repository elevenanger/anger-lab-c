/*
 * @author Anger
 * @date 2022/9/26
 * @brief 使得 print 函数可以按照零件编号的顺序显示零件
 */
#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"
#include "quick_sort.h"
#include "inventory.h"

int storage_size = INITIAL_SIZE;

int main(void) {

    struct part *inventory = malloc(sizeof(struct part) * storage_size);
    if (inventory == NULL) {
        printf("error cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    int num_parts = 0;

    char code;

    for(;;) {
        printf("i=>insert s=>search u=>update p=>print q=>quit\n");
        printf("ENTER OPERATION CODE : ");
        /* %c 前面的空格允许 scanf 在读入操作码之前忽略之前跳过的空白字符 */
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'i':
                insert(&inventory, &num_parts);
                break;
            case 's':
                search(inventory, num_parts);
                break;
            case 'u':
                update(inventory, num_parts);
                break;
            case 'p':
                print(inventory, num_parts);
                break;
            case 'q':
                free(inventory);
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
int find_part(struct part *inventory, int num_parts, int number) {
    int i;
    for (i = 0; i < num_parts; ++i)
        if (inventory[i].number == number)
            return i;
    return -1;
}

/**
 * 插入元素
 */
void insert(struct part **inventory, int *num_parts) {
    int part_number;

    if (*num_parts == storage_size) {
        printf("inventory is full, reallocate memory.\n");
        *inventory = increase(inventory);
    }

    printf("Enter part number : ");
    scanf("%d", &part_number);

    if (find_part(*inventory, *num_parts, part_number) >= 0) {
        printf("part already exist.\n");
        return;
    }

    (*inventory + *num_parts)->number = part_number;
    printf("Enter name : ");
    read_line((*inventory + *num_parts)->name, NAME_LEN);
    printf("Enter on hand : ");
    scanf("%d", &(*inventory + *num_parts)->on_hand);
    (*num_parts)++;
}

void search(struct part *inventory, int num_parts) {
    int i, number;

    printf("Enter part number : ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);

    if (i >= 0) {
        printf("part.name => %s\n", inventory[i].name);
        printf("quantity on hand => %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

void update(struct part *inventory, int num_parts) {
    int i, number, change;
    printf("Enter part number : ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter change in quantity on hand : ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found.\n");
}

void print(struct part *inventory, int num_parts) {
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

struct part *increase(struct part **inventory) {
    storage_size *= 2;
    *inventory = realloc(*inventory, sizeof(struct part) * storage_size);
    if (inventory == NULL) {
        printf("error , can't allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    return *inventory;
}