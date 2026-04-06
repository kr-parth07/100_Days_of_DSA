/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
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

int dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return 1;
        }
        else if (neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}