/*
 * @author Anger
 * @date 2022/9/12
 * @brief 查找最近的航班
 */
#include <stdio.h>

#define MINUTES_OF_NOON 720

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrive_time);

int main(void) {
    int hour, minute;
    int input_minutes, departure_time, arrive_time;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    input_minutes = hour * 60 + minute;
    find_closest_flight(input_minutes, &departure_time, &arrive_time);

    printf("Closet departure time is ");

    if (departure_time >= MINUTES_OF_NOON) {
        printf("%02d:%02d PM ",
               (departure_time / 60) == 12 ? 12 : (departure_time / 60) - 12,
               departure_time % 60);
    } else {
        printf("%02d:%02d AM ", departure_time / 60, departure_time % 60);
    }

    printf(",arriving at ");
    if (arrive_time >= MINUTES_OF_NOON) {
        printf("%02d:%02d PM ",
               (arrive_time / 60) == 12 ? 12 : (arrive_time / 60) - 12,
               arrive_time % 60);
    } else {
        printf("%02d:%02d AM ", arrive_time / 60, arrive_time % 60);
    }

    return 0;
}

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrive_time) {
    if (desired_time < (8 * 60 + 9 * 60 + 43) / 2) {
        *departure_time = 8 * 60;
        *arrive_time = 10 * 60 + 16;
    } else if (desired_time < (9 * 60 + 43 + 11 * 60 + 19) / 2) {
        *departure_time = 9 * 60 + 43;
        *arrive_time = 11 * 60 + 52;
    } else if (desired_time < (11 * 60 + 19 + 12 * 60 + 47) / 2) {
        *departure_time = 11 * 60 + 19;
        *arrive_time = 13 * 60 + 31;
    } else if (desired_time < (12 * 60 + 47 + 14 * 60) / 2) {
        *departure_time = 12 * 60 + 47;
        *arrive_time = 15 * 60;
    } else if (desired_time < (14 * 60 + 15 * 60 + 45) / 2) {
        *departure_time = 14 * 60;
        *arrive_time = 16 * 60 + 8;
    } else if (desired_time < (15 * 60 + 45 + 19 * 60) / 2) {
        *departure_time = 15 * 60 + 45;
        *arrive_time = 17 * 60 + 55;
    } else if (desired_time < (19 * 60 + 21 * 60 + 45) / 2) {
        *departure_time = 19 * 60;
        *arrive_time = 21 * 60 + 20;
    } else {
        *departure_time = 21 * 60 + 45;
        *arrive_time = 23 * 60 + 58;
    }
}