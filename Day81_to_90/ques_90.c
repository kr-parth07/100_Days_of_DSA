/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40


Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/

#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for(int i = 0; i < n; i++) {
        if(boards[i] > maxTime)
            return 0;

        if(currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, max = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if(boards[i] > max)
            max = boards[i];
    }

    int low = max;
    int high = sum;
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;   
        }
    }

    printf("%d\n", ans);

    return 0;
}