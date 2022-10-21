/*
 * @author Anger
 * @date 2022/10/21
 * @brief 将含有零件记录的文件进行合并
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 20
#define FILE_NAME_LEN 30
#define MAX_PARTS 100

struct part {
    char name[NAME_LEN + 1];
    int number;
    int on_hand;
} inventory[MAX_PARTS];

int main(int argc, char *argv[]) {
    FILE *file_in_1, *file_in_2, *file_out;
    struct part part_1, part_2;
    int num_1, num_2;

    if (argc != 4) {
        fprintf(stderr, "用法 combine 输入文件1 输入文件2 输出文件\n");
        exit(EXIT_FAILURE);
    }

    if ((file_in_1 = fopen(argv[1], "rb")) == NULL) {
        printf("无法打开文件 %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file_in_2 = fopen(argv[2], "rb")) == NULL) {
        printf("无法打开文件 %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((file_out = fopen(argv[3], "wb")) == NULL) {
        printf("无法打开文件 %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    /* 读取两个输入文件中的第一条数据 */
    num_1 = fread(&part_1, sizeof(struct part), 1, file_in_1);
    num_2 = fread(&part_2, sizeof(struct part), 1, file_in_2);

    /* 两个文件都有数据的情况下进入循环 */
    while (num_1 == 1 && num_2 == 1) {
        /* 第一个文件中的数据编号小于第二个文件中的数据编号 */
        if (part_1.number < part_2.number) {
            /* 将第一个文件的数据写入输出文件
             * 读取第一个文件下一条数据 */
            fwrite(&part_1, sizeof(struct part), 1, file_out);
            num_1 = fread(&part_1, sizeof(struct part), 1, file_in_1);
            /* 第一个文件中的数据编号大于第二个文件 */
        } else if (part_1.number > part_2.number) {
            /* 将第二个文件当前数据写入输出文件
             * 读取第二个文件下一条数据 */
            fwrite(&part_2, sizeof(struct part), 1, file_out);
            num_2 = fread(&part_2, sizeof(struct part), 1, file_in_2);
            /* 数据编号相等 */
        } else {
            /* name 属性不匹配则输出错误信息 */
            if (strcmp(part_1.name, part_2.name) != 0)
                fprintf(stderr, "%s %s 零件名称不相符\n", part_1.name, part_2.name);
            /* 两个 on_hand 属性值相加 */
            part_1.on_hand += part_2.on_hand;
            /* 数据写入输出文件
             * 分别读取两个文件的下一条数据 */
            fwrite(&part_1, sizeof(struct part), 1, file_out);
            num_1 = fread(&part_1, sizeof(struct part), 1, file_in_1);
            num_2 = fread(&part_2, sizeof(struct part), 1, file_in_2);
        }
    }

    /* 如果文件 1 还有数据则继续读取写入输出文件 */
    while (num_1 == 1) {
        fwrite(&part_1, sizeof(struct part), 1, file_out);
        num_1 = fread(&part_1, sizeof(struct part), 1, file_in_1);
    }
    /* 如果文件 2 还有数据则继续读取写入输出文件 */
    while (num_2 == 1) {
        fwrite(&part_2, sizeof(struct part), 1, file_out);
        num_2 = fread(&part_2, sizeof(struct part), 1, file_in_2);
    }

    fclose(file_in_1);
    fclose(file_in_2);
    fclose(file_out);

    exit(EXIT_SUCCESS);
}