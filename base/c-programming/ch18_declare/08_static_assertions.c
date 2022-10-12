/*
 * @author Anger
 * @date 2022/10/12
 * @brief c11 静态断言
 * _static_assert 可以在编译期间进行诊断和检查工作
 */
#define UNIT 1000

void static_assertion(void);

int main(void) {
    static_assertion();
    return 0;
}

void static_assertion() {
    /* _Static_assert(常量表达式,字面串)
     * 常量表达式必须是一个整型常量表达式
     * 如果值不为 0 则没有什么效果
     * 如果值为 0 则会输出字面串的诊断信息
     * */
    _Static_assert(UNIT >= 100 , "too small number.\n");
}
