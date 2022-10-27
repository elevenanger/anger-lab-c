/*
 * @author Anger
 * @date 2022/10/27
 * @brief 格式日期
 */
#include <stdio.h>
#include <time.h>

int main(void) {

    time_t cur = time(NULL);
    struct tm *p;
    char s[37], date[9], time[12];

    p = localtime(&cur);
    strftime(s, sizeof(s), "%A, %B %d, %Y %I:%M", p);
    printf("%s%c\n", s, p->tm_hour <= 11 ? 'a':'p');

    strftime(s, sizeof(s), "%a, %d %b %y  %H:%M", localtime(&cur));
    printf("%s\n", s);

    strftime(date, sizeof(date), "%m/%d/%y", p);
    strftime(time, sizeof(time), "%I:%M:%S %p", p);

    printf("%s  %s\n", date, time[0] == '0' ? &time[1] : time);

    return 0;
}