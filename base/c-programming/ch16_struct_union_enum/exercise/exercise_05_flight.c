/*
 * @author Anger
 * @date 2022/9/26
 */
#include <stdio.h>
#define SIZE(a) ((int) sizeof(a) / sizeof (a[0]))


const struct flight {
    int departure;
    int arrival;
} times[] = {
        {480, 616}, {583,  712}, {679,  811},   {767,  900},
        {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};

void print(struct flight time);

int main(void) {
    int minute_of_time, hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    minute_of_time = hour * 60 + minute;

    for (int i = 0; i < SIZE(times) - 1; ++i) {
        if (minute_of_time > times[i].departure &&
                minute_of_time <= times[i].arrival)
            print(times[i]);
    }

    return 0;

}

void print(struct flight time) {
    printf("departure at %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           time.departure/60 > 12 ? time.departure/60 - 12 : time.departure/60,
           time.departure%60, time.departure > 719 ? 'p' : 'a',
           time.arrival/60 > 12 ? time.arrival/60 - 12 : time.arrival/60,
           time.arrival%60, time.arrival > 719 ? 'p' : 'a');
}