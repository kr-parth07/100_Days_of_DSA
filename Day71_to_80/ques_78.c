/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int adj[MAX][MAX];

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int selected[MAX] = {0};
    selected[1] = 1;

    int edges = 0;
    int totalWeight = 0;

    while(edges < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for(int i = 1; i <= n; i++) {
            if(selected[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!selected[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        totalWeight += min;
        edges++;
    }

    printf("%d\n", totalWeight);

    return 0;
}