/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V; 

bool dfs(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {

            if (!visited[i] && dfs(i))
                return true;

            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }

    return false;
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

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}