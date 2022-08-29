/*
 * @author 刘昂林 
 * @date 2022/8/29
 * @brief 计算球体的体积
 */
#include <stdio.h>
#define PI 3.14
#define SPHERE_VOLUME_FACTOR  (4.0f / 3.0f)
#define CAL_CUBE(r)  (r * r * r)

float cal_sphere_volume(float radius) {
    return SPHERE_VOLUME_FACTOR * PI * CAL_CUBE(radius);
}

int main(void) {
    float r;
    printf("Enter radius : \n");

    scanf("%f", &r);

    printf("Sphere volume : %.2f", cal_sphere_volume(r));

    return 0;
}