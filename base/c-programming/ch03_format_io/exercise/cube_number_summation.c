/*
 * @author 刘昂林 
 * @date 2022/8/30
 * @brief 对于矩形数字进行求和
 */
#include <stdio.h>

int main() {

    int n1, n2, n3, n4,
        n5, n6, n7, n8,
        n9, n10, n11, n12,
        n13, n14, n15, n16;

    puts("Enter the number : ");

    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
          &n1, &n2, &n3, &n4,
          &n5, &n6, &n7, &n8,
          &n9, &n10, &n11, &n12,
          &n13, &n14, &n15, &n16);

    printf("Row sums : %d %d %d %d\n"
           "Column sums : %d %d %d %d\n"
           "Diagonal sums : %d %d",
           n1 + n2 + n3 + n4,
           n5 + n6 + n7 + n8,
           n9 + n10 + n11 + n12,
           n13 + n14 + n15 + n16,
           n1 + n5 + n9 + n13,
           n2 + n6 + n10 + n14,
           n3 + n7 + n11 + n15,
           n4 + n8 + n12 + n16,
           n1 + n6 + n11 + n16,
           n4 + n7 + n10 + n13);

    return 0;
}