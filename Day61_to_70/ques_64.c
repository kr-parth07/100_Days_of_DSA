/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->data = u;
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

void bfs(int s, int n) {
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int s;
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    bfs(s, n);

    return 0;
}