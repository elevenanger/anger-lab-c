/*
 * @author Anger
 * @date 2022/10/24
 * @brief 信号测试
 */
#include <signal.h>
#include <stdio.h>

void handler(int sig);
void raise_sig(void);

int main(void) {
    void (*orig_handler)(int) = SIG_DFL;

    printf("安装 SIGINT 信号处理器\n");
    signal(SIGINT, handler);
    raise_sig();

    printf("复原原来的信号处理器\n");
    signal(SIGINT, orig_handler);
    raise_sig();

    printf("程序正常终止\n");
    return 0;
}

void handler(int sig) {
    fprintf(stderr, "处理 %d 信号", sig);
}

void raise_sig(void) {
    raise(SIGINT);
}