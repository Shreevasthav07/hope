
#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[20];

int find(int x) {
    while(parent[x] != x)
        x = parent[x];
    return x;
}

int main() {
    struct Edge e[50], temp;
    int n, m, i, j, count = 0, total = 0;
    int a, b;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    // Sort edges by weight
    for(i = 0; i < m-1; i++) {
        for(j = 0; j < m-i-1; j++) {
            if(e[j].w > e[j+1].w) {
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }

    // Initialize parent array
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("MST Edges:\n");

    for(i = 0; i < m && count < n-1; i++) {
        a = find(e[i].u);
        b = find(e[i].v);

        if(a != b) {
            printf("%d - %d : %d\n", e[i].u, e[i].v, e[i].w);
            total += e[i].w;
            parent[a] = b;
            count++;
        }
    }

    if(count == n-1)
        printf("Minimum Cost = %d\n", total);
    else
        printf("MST not possible\n");

    return 0;
}
