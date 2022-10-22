/*
 * @author Anger
 * @date 2022/10/22
 * @brief 从文件中读取航班时间
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 255
#define MAX_TIMES 100

int read_line(char str[], int n, FILE *fp);

int compare(const void *v1, const void *v2);

int main() {

    FILE *fp;
    char line[MAX_LEN];
    int i, hour, min, flights, user_time,
        dep_hr, dep_min, arr_hr, arr_min,
        departures[MAX_TIMES], arrivals[MAX_TIMES];

    if ((fp = fopen("flights.dat", "r")) == NULL) {
        fprintf(stderr, "无法打开文件\n");
        exit(EXIT_FAILURE);
    }

    i = 0;

    while (read_line(line, MAX_LEN, fp) != 0) {
        sscanf(line, "%d:%d %d:%d", &dep_hr, &dep_min, &arr_hr, &arr_min);
        departures[i] = dep_hr * 60 + dep_min;
        arrivals[i] = arr_hr * 60 + arr_min;
        i++;

        if (i == MAX_TIMES) {
            fprintf(stderr, "文件数据过大，只读取前 %d 行数据\n", MAX_TIMES);
            break;
        }
    }
    flights = i;

    qsort(departures, flights, sizeof(int), compare);
    qsort(arrivals, flights, sizeof(int), compare);

    printf("输入 24 小时制离开时间 (HH:mm) : ");
    scanf("%d:%d", &hour, &min);
    user_time = hour * 60 + min;

    for (i = 0; i < flights; ++i) {
        if (abs(user_time - departures[i]) <=
            abs(user_time - departures[i + 1]))
            break;
    }

    printf("最近的航班离开时间：%.2d:%.2d，抵达时间：%.2d:%.2d\n",
           departures[i] / 60, departures[i] % 60,
           arrivals[i] / 60, arrivals[i] % 60);
    fclose(fp);

    exit(EXIT_SUCCESS);
}

int read_line(char str[], int n, FILE *fp) {
    int ch, i = 0;
    while (isspace(ch = getc(fp)));

    while (ch != '\n' && ch != EOF) {
        if (i < n){
            str[i++] = ch;
        }
        ch = getc(fp);
    }

    str[i] = '\0';
    return i;
}

int compare(const void *v1, const void *v2) {
    return (*(int *)v1 - *(int *)v2);
}
