#include <stdio.h>

#define SWAP(x, y, t)((t) = (x), (x) = (y), (y) = (t))

int solve(int n)
{
    int arr[n], temp, count = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                SWAP(arr[j], arr[j+1], temp);
                count++;
            }

    return count;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("Minimum exchange operations : %d\n", solve(n));
    }

    return 0;
}