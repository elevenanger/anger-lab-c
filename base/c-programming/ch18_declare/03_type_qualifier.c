/*
 * @author Anger
 * @date 2022/10/2
 * @brief 类型限定符
 */
#include <stdio.h>

typedef struct {
    char *name;
    char sex;
} person;

typedef union {
    char *home;
    char *company;
} address;

/* const 用来声明一些类似变量的对象
 * 但是这些变量是只读的
 * 程序可以访问 const 类型对象的值
 * 但是无法改变它
 * 声明 const 的好处 ：
 * 1、const 是文档格式，声明对象是 const 类型可以提示任何阅读程序的人
 * 2、编译器可以检查程序有没有改变 const 类型对象的值
 * 3、为特定类型的应用编写程序时，编译器用 const 来识别需要存储到 ROM 的数据 */
void const_type_qualifier(void);

int main(void) {
    const_type_qualifier();
    return 0;
}

void const_type_qualifier(void) {
    printf("const 类型限定符 => %s\n", __FUNCTION__ );
    const int i;
    static const int sci;
    const address address1;
    const person person1;
    const char name[30];
    const char *p;
}
