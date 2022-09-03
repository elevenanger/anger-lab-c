/*
 * @author Anger
 * @date 2022/9/3
 * @brief 控制用户仅允许输入十二小时制的时间
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    unsigned int hour, time, ch1, ch2;

    printf("Enter a 12-hour-time : ");

    /* 获取时间，因为是混合格式字符，所以使用 scanf */
    scanf("%d:%2d", &hour, &time);
    if (hour > 12 || time > 60) {
        printf("Error time format!\n");
        return 1;
    }

    /* 获取表示表示上午或者下午的字符第一位 */
    while ((ch1 = getchar())) {
        /* 遇到空白字符则跳过 */
        if (ch1 == ' '|| ch1 == '\b' || ch1 == '\t' || ch1 == '\v')
            continue;

        /* 将字符转换成大写 如果是 A 或者 P 则获取为第一位字符，结束循环*/
        ch1 = toupper((char) ch1);
        if (ch1 == 'A' || ch1 == 'P')
            break;

        /* 非空白字符而且不是 A 或者 P 则终止程序 */
        printf("Error time format!\n");
        return 1;
    }

    /* 获取表示上午或者下午的字符的第二位,遇到回车则结束 */
    while ((ch2 = getchar()) != '\n') {
        /* 如果是 M 则将第二位字符赋值为 M 结束循环 */
        if ( (ch2 = toupper((char) ch2)) == 'M')
            break;
        /* 否则报错，终止程序 */
        printf("Error time format!\n");
        return 1;
    }

    /* 打印时间 */
    printf("Time is : %d:%d %c%c\n", hour, time, ch1, ch2);

    /* 转换成 24 小时制 ch1 为 P 则加 12 */
    if (ch1 == 'P') hour += 12;
    /* hour 为 24 则减去 24 */
    if (hour == 24) hour -= 24;
    printf("Equivalent 24-hour time : %d:%d\n", hour, time);

    return 0;
}