/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/
#include <stdio.h>

#define MAX 100

int main()
{
    int q[MAX];
    int front = 0, rear = -1;
    int n, m, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        int temp = q[front];
        front = (front + 1) % MAX;

        rear = (rear + 1) % MAX;
        q[rear] = temp;
    }

    int count = n;
    int idx = front;

    for(i = 0; i < count; i++)
    {
        printf("%d ", q[idx]);
        idx = (idx + 1) % MAX;
    }

    return 0;
}