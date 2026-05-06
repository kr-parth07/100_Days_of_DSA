/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    while(1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

int minMeetingRooms(Meeting intervals[], int n) {
    if(n == 0)
        return 0;

    qsort(intervals, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    heap[heapSize++] = intervals[0].end;

    int maxRooms = 1;

    for(int i = 1; i < n; i++) {

        if(intervals[i].start >= heap[0]) {
            heap[0] = intervals[i].end;
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = intervals[i].end;
            heapifyUp(heap, heapSize);
            heapSize++;
        }

        if(heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting intervals[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}