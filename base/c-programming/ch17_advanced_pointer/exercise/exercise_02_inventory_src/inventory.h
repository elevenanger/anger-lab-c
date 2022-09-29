/*
 * @author Anger
 * @date 2022/9/26
 */

#ifndef ANGER_LAB_C_INVENTORY_H
#define ANGER_LAB_C_INVENTORY_H

#define NAME_LEN 20
#define INITIAL_SIZE 1

struct part {
    char name[NAME_LEN + 1];
    int number;
    int on_hand;
};

void insert(struct part **inventory, int *num_parts);
void search(struct part *inventory, int num_parts);
void update(struct part *inventory, int num_parts);
void print(struct part *inventory, int num_parts);
int find_part(struct part *inventory, int num_parts, int number);
struct part *increase(struct part **inventory);
int part_sort(const void *a, const void *b);
#endif //ANGER_LAB_C_INVENTORY_H
