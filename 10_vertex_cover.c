
#include <stdio.h>

int main()
{
    int a[10][10] = {0};
    int selected[10] = {0};
    int n, e, u, v, i, j, count = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &e);

    printf("Enter edges (u v):\n");

    for(i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                if(selected[i] == 0 && selected[j] == 0)
                {
                    selected[i] = 1;
                    selected[j] = 1;
                }
            }
        }
    }

    printf("Vertex Cover: ");

    for(i = 0; i < n; i++)
    {
        if(selected[i] == 1)
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nNumber of selected vertices = %d", count);
    printf("\nApproximation ratio <= 2\n");

    return 0;
}
