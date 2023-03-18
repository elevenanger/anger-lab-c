/*
 * @author Anger
 * @date 2023/3/18
 * @brief 阿姆达尔定律
 * s = 1 / (1 - α + (α / κ))
 * s 总的相对性能提升
 * α 性能提升这一部分占总程序的比例
 * κ 这部分的性能提升
 */
#include "stdio.h"
#include "string.h"

double cal_s(double alpha, double k);
double cal_k(double alpha, double s);

int main(int argc, char *argv[]) {

    double first, second;

    char *usage = "用法：csapp_01_amdahl --s alpha k\n"
                  "      csapp_01_amdahl --k alpha s\n";

    if (argc != 4) {
        fprintf(stderr, "%s", usage);
        return 1;
    }

    sscanf(argv[2], "%lf", &first);

    if(first <= 0 || first > 1) {
        fprintf(stderr, "α 取值范围为 0~1");
        return 1;
    }

    sscanf(argv[3], "%lf", &second);

    if (strcmp(argv[1], "--s") == 0) {
        printf("s = %.2lf", cal_s(first, second));
    } else if (strcmp(argv[1], "--k") == 0) {
        printf("k = %.2f", cal_k(first, second));
    } else {
        fprintf(stderr, "%s", usage);
        return 1;
    }

    return 0;
}

double cal_s(double alpha, double k) {
    return 1 / (1 - alpha + (alpha / k));
}

double cal_k(double alpha, double s) {
    return s * alpha / (1 - s + s * alpha);
}