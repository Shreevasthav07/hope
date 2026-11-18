
#include <stdio.h>

int a[20], selected[20], n, target;

void subset(int i, int sum)
{
    int j;

    if(sum == target)
    {
        printf("{ ");
        for(j = 0; j < n; j++)
            if(selected[j] == 1)
                printf("%d ", a[j]);

        printf("}\n");
        return;
    }

    if(i == n || sum > target)
        return;

    // Include the element
    selected[i] = 1;
    subset(i + 1, sum + a[i]);

    // Exclude the element
    selected[i] = 0;
    subset(i + 1, sum);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets are:\n");
    subset(0, 0);

    return 0;
}
