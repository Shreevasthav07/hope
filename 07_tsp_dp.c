
#include <stdio.h>

#define INF 999999

int n, cost[10][10], dp[10][1024];

int tsp(int city, int mask)
{
    int i, ans = INF, temp, newMask;

    if(mask == (1 << n) - 1)
        return cost[city][0];

    if(dp[city][mask] != -1)
        return dp[city][mask];

    for(i = 0; i < n; i++)
    {
        if((mask & (1 << i)) == 0)
        {
            newMask = mask | (1 << i);

            temp = cost[city][i] + tsp(i, newMask);

            if(temp < ans)
                ans = temp;
        }
    }

    return dp[city][mask] = ans;
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for(i = 0; i < n; i++)
        for(j = 0; j < (1 << n); j++)
            dp[i][j] = -1;

    printf("Minimum travelling cost = %d\n", tsp(0, 1));

    return 0;
}
