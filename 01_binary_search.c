#include <stdio.h>
int main()
{
    int a[100], n, key, low, high, mid, comparisons = 0;
    int found = -1, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        comparisons++;
        if (a[mid] == key)
        {
            found = mid;
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", found + 1);
    printf("Number of comparisons = %d\n", comparisons);
    return 0;
}