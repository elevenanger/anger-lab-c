/*
 * @author Anger
 * @date 2022/9/26
 * @brief  
 */

#ifndef ANGER_LAB_C_INVENTORY_H
#define ANGER_LAB_C_INVENTORY_H

#define NAME_LEN 20
#define MAX_PARTS 100

struct part {
    char name[NAME_LEN + 1];
    int number;
    int on_hand;
};

void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);
int find_part(struct part inventory[], int num_parts, int number);
#endif //ANGER_LAB_C_INVENTORY_H
