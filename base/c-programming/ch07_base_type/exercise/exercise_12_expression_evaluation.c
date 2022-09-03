/*
 * @author Anger
 * @date 2022/9/3
 * @brief 对表达式进行求值
 * 表达式的操作数都是浮点数，运算符都是 + - * /
 * 表达式从左向右求值(所有运算符的优先级都一样)
 */
#include <stdio.h>


int main(void) {
    double result = 0, cur_val;
    /* 读取第一个操作数 */
    scanf("%lf", &result);
    /* 运算操作符 */
    char operate;
    while ((operate = (char) getchar()) != '\n') {
        /* 读取下一个操作数 */
        scanf("%lf", &cur_val);
        printf("result = %lf cur_val = %lf \n", result, cur_val);
        /* 根据当前的算数运算符执行相应的算数运算 */
        switch (operate) {
            case '+': result += cur_val; break;
            case '-': result -= cur_val; break;
            case '*': result *= cur_val; break;
            case '/': result /= cur_val; break;
            default: break;
        }
    }

    printf("result = %f", result);

    return 0;
}