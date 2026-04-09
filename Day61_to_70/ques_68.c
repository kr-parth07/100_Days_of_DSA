/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int V;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front > rear;
}

void topologicalSort() {
    for (int i = 0; i < V; i++)
        indegree[i] = 0;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j])
                indegree[j]++;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            enqueue(i);

    int count = 0;

    printf("Topological Order:\n");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < V; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }

        count++;
    }

    if (count != V)
        printf("\nCycle detected! Topological sort not possible.\n");
}

int main() {
    int E, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}