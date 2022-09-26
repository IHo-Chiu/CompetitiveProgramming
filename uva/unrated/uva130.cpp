#include <stdio.h>

int main()
{
    int n, k;
    int arr[101];
    while (scanf("%d %d", &n, &k) != EOF)
    {
        if (n == 0 && k == 0)
            break;

        for (int i = 0; i < n; i++)
            arr[i] = i;

        int kill = n-1, replace = 0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < k+1; kill = (kill+1)%n)
                if (arr[kill] != -1) {
                    j++;
                    if (j == k+1) break;
                }

            replace = kill;
            arr[kill] = -1;
            for (int j = 0; j < k; replace = (replace+1)%n)
                if (arr[replace] != -1) {
                    j++;
                    if (j == k) break;
                }

            arr[kill] = arr[replace];
            arr[replace] = -1;
        }

        printf("%d\n", (n-arr[kill])%n + 1);
    }

    return 0;
}