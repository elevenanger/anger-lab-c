/*
 * @author Anger
 * @date 2022/9/12
 * @brief 输出一个分数的最简分式
 */
#include <stdio.h>

int largest_divisor(int m, int n);

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator);

int main(void) {

    int numerator, denominator, reduced_numerator, reduced_denominator;

    printf("Enter a fraction : ");
    scanf("%d/%d", &numerator, &denominator);
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("In lowest form : %d/%d",
           reduced_numerator, reduced_denominator);
    return 0;
}

int largest_divisor(int m, int n) {
    int d;

    if (m == 0 || n == 0) return 1;

    if (m == n) goto output;

    if (m < n) {
        d = m;
        m = n;
        n = d;
    }

    while (n != 0) {
        d = n;
        n = m % n;
        m = d;
    }

    output:
    printf("Greatest common divisor : %d\n", m);

    return m;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator) {

    int max_divisor = largest_divisor(numerator, denominator);

    *reduced_numerator = numerator / max_divisor;
    *reduced_denominator = denominator / max_divisor;
}
