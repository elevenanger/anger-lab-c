/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 解析ISBN
 */
#include <stdio.h>

int main() {
    int gs1_prefix, group_id, publisher_code, item_number, check_digit;

    puts("Enter ISBN : ");
    scanf("%d-%d-%d-%d-%d",
          &gs1_prefix, &group_id, &publisher_code, &item_number, &check_digit);

    printf("GS1 prefix : %d\n"
           "Group identifier : %d\n"
           "Publisher code : %d\n"
           "Item number : %d\n"
           "Check digit : %d\n",
           gs1_prefix, group_id, publisher_code, item_number, check_digit);

    return 0;
}
