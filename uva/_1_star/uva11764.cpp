#include <stdio.h>

int main()
{
    int q, n, h, l;
    int arr[50];
    scanf("%d", &q);
    for (int qq = 1; qq <= q; qq++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        h = l = 0;
        for (int i = 1; i < n; i++)
            if (arr[i-1] < arr[i])
                h++;
            else if (arr[i-1] > arr[i])
                l++;

        printf("Case %d: %d %d\n", qq, h, l);
    }

    return 0;
}