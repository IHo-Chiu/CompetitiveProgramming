#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    int n, x, y;
    int arr[50];
    while (scanf("%d", &n) != EOF && n > 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        x = y = 0;
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++, y++)
                if (gcd(arr[i], arr[j]) == 1)
                    x++;

        if (x)
            printf("%lf\n", sqrt((double)y*6/x));
        else
            printf("No estimate for this data set.\n");
    }

    return 0;
}