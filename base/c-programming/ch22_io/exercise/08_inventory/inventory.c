/*
 * @author Anger
 * @date 2022/9/24
 * @brief 仓储程序
 */
#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define NAME_LEN 20
#define FILE_NAME_LEN 30
#define MAX_PARTS 100

struct part {
    char name[NAME_LEN + 1];
    int number;
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void saving_data(void);
void read_data(void);

int main(void) {

    char code;

    for(;;) {
        printf("i=>insert s=>search u=>update p=>print q=>quit \n"
               "d => storage r => read from data\n");
        printf("ENTER OPERATION CODE : ");
        /* %c 前面的空格允许 scanf 在读入操作码之前忽略之前跳过的空白字符 */
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'd':
                saving_data();
                break;
            case 'r':
                read_data();
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

    for (i = 0; i < num_parts; i++)
    printf("%7d        %-25s%11d\n",
           inventory[i].number,
           inventory[i].name,
           inventory[i].on_hand);
}

void saving_data(void) {
    FILE *fp;
    char file_name[FILE_NAME_LEN];

    printf("Enter name of input file : ");
    read_line(file_name, FILE_NAME_LEN);

    if ((fp = fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    /* 将数组数据写入文件 */
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
}

void read_data(void) {
    FILE *fp;
    char file_name[FILE_NAME_LEN];

    printf("Enter name of input file : ");
    read_line(file_name, FILE_NAME_LEN);

    if ((fp = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    /* 将文件数据读入库存数组 */
    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
    fclose(fp);
}