
#include <stdio.h>

int graph[20][20], visited[20];
int stack[20], top = -1, n;

/* DFS function */
void dfs(int u) {
    int v;

    visited[u] = 1;

    for (v = 0; v < n; v++) {
        if (graph[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }

    stack[++top] = u;
}

int main() {
    int e, i, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &e);

    printf("Enter directed edges (u v):\n");

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
    }

    /* Perform DFS */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    /* Print topological order */
    printf("Topological order: ");

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
