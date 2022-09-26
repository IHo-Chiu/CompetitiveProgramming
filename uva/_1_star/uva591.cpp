#include <stdio.h>
#include <math.h>

int main()
{
    int n, mean, cnt, set = 0;
    int arr[200];
    while (scanf("%d", &n) != EOF && n > 0)
    {
        set++;
        printf("Set #%d\n", set);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        mean = 0;
        for (int i = 0; i < n; i++)
            mean += arr[i];
        mean /= n;

        cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += abs(mean - arr[i]);
        cnt /= 2;

        printf("The minimum number of moves is %d.\n\n", cnt);
    }

    return 0;
}