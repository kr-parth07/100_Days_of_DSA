/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node) {
    visited[node] = 1;

    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    dfs(1);

    int isConnected = 1;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            isConnected = 0;
            break;
        }
    }

    if(isConnected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}