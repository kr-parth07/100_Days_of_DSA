/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for(int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for(int i = 0; i < n; i++) {

        double time =
            (double)(target - cars[i].position) / cars[i].speed;

        if(time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    int position[n], speed[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}