/*
 * @author Anger
 * @date 2022/10/22
 * @brief 从命令行中读取日期 mm-dd-yyyy mm/dd/yyyy 格式
 * 转换成 月份英文 dd, yyyy 格式
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int mm, dd, yyyy;

    const char* MONTHS[12] = {"January", "February", "March", "April",
                              "May", "June", "July", "August", "September",
                              "October", "November", "December"};

    if (argc != 2) {
        fprintf(stderr, "用法 fdate mm-dd-yyyy 或者 fdate mm/dd/yyyy\n");
        exit(EXIT_FAILURE);
    }

    if(sscanf(argv[1], "%2d%*[-/]%2d%*[-/]%4d", &mm, &dd, &yyyy) != 3) {
        fprintf(stderr, "输入格式错误 %s\n", argv[1]);
    }

    fprintf(stdout, "%s %2d,%4d", MONTHS[mm], dd, yyyy);

    exit(EXIT_SUCCESS);

}