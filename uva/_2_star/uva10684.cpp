#include <stdio.h>
#include <memory.h>

int main()
{
    int n, cnt, max;
    int arr[10000];
    while (scanf("%d", &n) != EOF && n > 0)
    {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        cnt = max = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += arr[i];
            if (cnt < 0) cnt = 0;
            if (cnt > max) max = cnt;        
        }

        if (max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
    }

    return 0;
}