/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    if(n <= 0)
        return;

    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for(int i = 1; i < n; i++) {

        if(arr[i].start <= result[index].end) {

            if(arr[i].end > result[index].end)
                result[index].end = arr[i].end;

        } else {
            index++;
            result[index] = arr[i];
        }
    }

    for(int i = 0; i <= index; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}