/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
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
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges:\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
            components++;
        }
    }

    printf("Number of connected components = %d\n", components);

    return 0;
}