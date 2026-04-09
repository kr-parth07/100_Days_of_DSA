/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;
int V;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    push(v);
}

void topologicalSort() {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Topological Order:\n");

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
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

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}