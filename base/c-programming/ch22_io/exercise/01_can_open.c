/*
 * @author Anger
 * @date 2022/10/19
 * @brief 扩展 canopen 程序
 * 可以将任意数量的文件放在命令行中
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        printf("用法：canopen 文件名\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s 没有读权限\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        printf("%s 拥有读权限\n", argv[i]);
        fclose(fp);
    }

    exit(EXIT_SUCCESS);
}
