/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/
#include <stdio.h>

#define MAX 1000

int main() {
    int n, i;
    int arr[MAX];

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int maxLen = 0;

    int map[2001];

    for(i = 0; i < 2001; i++) {
        map[i] = -2;
    }

    map[1000] = -1;

    for(i = 0; i < n; i++) {
        sum += arr[i];

        int index = sum + 1000;

        if(map[index] != -2) {
            int length = i - map[index];
            if(length > maxLen) {
                maxLen = length;
            }
        } else {
            map[index] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}