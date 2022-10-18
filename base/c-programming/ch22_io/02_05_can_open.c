/*
 * @author Anger
 * @date 2022/10/18
 * @brief 从命令行中获取文件
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        printf("用法：canopen 文件名\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("%s 没有读权限\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%s 拥有读权限\n", argv[1]);
    fclose(fp);

    exit(EXIT_SUCCESS);
}