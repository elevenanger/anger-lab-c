/*
 * @author Anger
 * @date 2023/3/22
 * @brief 按字节逐个字节表示数据
 */
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

void test_show_bytes(int x);

int main() {

    test_show_bytes(0xfedcba98);

    test_show_bytes(12345);

    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;

    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);

    return 0;
}

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; ++i)
        printf("%.2x ", start[i]);

    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int x) {
    int i_val = x;
    float f_val = (float) i_val;
    int *p_val = &i_val;
    show_int(i_val);
    show_float(f_val);
    show_pointer(p_val);
}
