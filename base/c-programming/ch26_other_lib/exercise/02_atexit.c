/*
 * @author Anger
 * @date 2022/10/27
 */
#include <stdlib.h>
#include <stdio.h>

void f1(void);
void f2(void);

int main(void) {

    atexit(f2);
    atexit(f1);

    return 0;
}

void f1(void) {
    printf("That's all,");
}


void f2(void) {
    printf("folks.");
}