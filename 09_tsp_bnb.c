
#include <stdio.h>

#define INF 999999

int n, cost[10][10], minCost = INF;

struct Node
{
    int path[10], visited[10];
    int level, city, total;
};

struct Node q[10000];
int front = 0, rear = 0;

void insert(struct Node x)
{
    q[rear++] = x;
}

struct Node removeNode()
{
    return q[front++];
}

int bound(struct Node x)
{
    int i, b = x.total, min;

    for(i = 0; i < n; i++)
    {
        if(x.visited[i] == 0)
        {
            min = INF;

            for(int j = 0; j < n; j++)
                if(i != j && cost[i][j] < min)
                    min = cost[i][j];

            b += min;
        }
    }

    return b;
}

int main()
{
    int i, j, v, b;
    struct Node x, y;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for(i = 0; i < n; i++)
        x.visited[i] = 0;

    x.path[0] = 0;
    x.visited[0] = 1;
    x.city = 0;
    x.level = 1;
    x.total = 0;

    insert(x);

    while(front < rear)
    {
        x = removeNode();

        if(x.level == n)
        {
            v = x.total + cost[x.city][0];

            if(v < minCost)
                minCost = v;

            continue;
        }

        for(i = 1; i < n; i++)
        {
            if(x.visited[i] == 0)
            {
                y = x;

                y.path[y.level] = i;
                y.visited[i] = 1;
                y.total = x.total + cost[x.city][i];
                y.city = i;
                y.level++;

                b = bound(y);

                if(b < minCost)
                    insert(y);
            }
        }
    }

    printf("Minimum travelling cost = %d\n", minCost);

    return 0;
}
