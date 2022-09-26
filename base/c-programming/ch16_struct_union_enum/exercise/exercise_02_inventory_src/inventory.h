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
} inventory[MAX_PARTS];

#endif //ANGER_LAB_C_INVENTORY_H
