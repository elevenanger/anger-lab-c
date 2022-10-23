/*
 * @author Anger
 * @date 2022/10/23
 * @brief 对方程求值
 */
#include <stdio.h>
#include <math.h>

int main(void) {

    double a, b, c, radical, root1, root2;

    printf("计算 ax^2 + bx + c = 0, 输入 a：");
    scanf("%lf", &a);
    printf("输入 b：");
    scanf("%lf", &b);
    printf("输入 c：");
    scanf("%lf", &c);

    radical = b * b - (4 * a * c);

    if (radical < 0)
        printf("平方根是复数\n");\
    else {
    radical = sqrt(radical);
    root1 = (-b + radical) / (2 * a);
    root2 = (-b - radical) / (2 * a);

    if (root1 == root2)
        printf("1 个解 x = %lf\n", root1);
    else
        printf("2 个解 x = %lf 或者 x = %lf\n", root1, root2);
}

    return 0;
}