/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right,
           int counts[], Pair temp[]) {

    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while(i <= mid && j <= right) {

        if(arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], int left, int right,
               int counts[], Pair temp[]) {

    if(left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, counts, temp);
    mergeSort(arr, mid + 1, right, counts, temp);

    merge(arr, left, mid, right, counts, temp);
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    Pair arr[n], temp[n];
    int counts[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        arr[i].val = nums[i];
        arr[i].index = i;

        counts[i] = 0;
    }

    mergeSort(arr, 0, n - 1, counts, temp);

    for(int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }

    return 0;
}