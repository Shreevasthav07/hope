#include <stdio.h>
int bruteCount = 0, dcCount = 0;
void bruteForce(int a[], int n, int *mn, int *mx)
{
    int i;
    *mn = *mx = a[0];
    for (i = 1; i < n; i++)
    {
        bruteCount++;
        if (a[i] < *mn)
            *mn = a[i];
        bruteCount++;
        if (a[i] > *mx)
            *mx = a[i];
    }
}
void divideConquer(int a[], int low, int high, int *mn, int *mx)
{
    int mid, min1, max1, min2, max2;
    if (low == high)
    {
        *mn = *mx = a[low];
        return;
    }
    if (high == low + 1)
    {
        dcCount++;
        if (a[low] < a[high])
        {
            *mn = a[low];
            *mx = a[high];
        }
        else
        {
            *mn = a[high];
            *mx = a[low];
        }
        return;
    }
    mid = (low + high) / 2;
    divideConquer(a, low, mid, &min1, &max1);
    divideConquer(a, mid + 1, high, &min2, &max2);
    dcCount++;
    *mn = (min1 < min2) ? min1 : min2;
    dcCount++;
    *mx = (max1 > max2) ? max1 : max2;
}
int main()
{
    int a[100], n, i, mn, mx, mn2, mx2;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bruteForce(a, n, &mn, &mx);
    printf("\nBrute force: Min = %d, Max = %d", mn, mx);
    printf(", Comparisons = %d\n", bruteCount);
    divideConquer(a, 0, n - 1, &mn2, &mx2);
    printf("Divide and conquer: Min = %d, Max = %d", mn2, mx2);
    printf(", Comparisons = %d\n", dcCount);
    return 0;
}