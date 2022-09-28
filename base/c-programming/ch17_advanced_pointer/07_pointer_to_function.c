/*
 * @author Anger
 * @date 2022/9/28
 * @brief 指向函数的指针
 */
#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 25


struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[] = {
        {.number = 1, .on_hand = 10, .name = "No.1"},
        {.number = 3, .on_hand = 12, .name = "No.3"},
        {.number = 2, .on_hand = 15, .name = "No.2"}};

int compare_parts(const void *part1, const void *part2);
void print_inventory(struct part parts[], int n);

int main(void) {

    /* qsort 函数
     * 对于数组进行排序
     * 传入需要排序的数组，数组的元素数量，每个元素的大小还有排序函数 */
    qsort(inventory, 3, sizeof(struct part), compare_parts);
    print_inventory(inventory, 3);

    return 0;
}

/**
 * 实现 qsort 函数中的 compar 函数
 * @param part1 第一个元素
 * @param part2 第二个元素
 * @return 比较值
 */
int compare_parts(const void *part1, const void *part2) {
    /* compar 函数的参数是 void * 类型
     * 需要将其转换为 struct part 类型 */
    const struct part *p1 = part1;
    const struct part *p2 = part2;

    return p1->number - p2->number;
}

void print_inventory(struct part parts[], int n) {
    for (int i = 0; i < n; ++i)
        printf("Part name => %s\t"
               "Part number => %d\t"
               "Part on_hand => %d\n",
               inventory[i].name,
               inventory[i].number,
               inventory[i].on_hand);
}
