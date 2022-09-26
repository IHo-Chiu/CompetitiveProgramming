#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);

        int max, ans, a;
        scanf("%d", &max);
        scanf("%d", &a);
        ans = max - a;
        if (a > max)
            max = a;

        for (int j = 2; j < n; j++)
        {
            scanf("%d", &a);
            if (max - a > ans)
                ans = max - a;
            if (a > max)
                max = a;
        }

        printf("%d\n", ans);
    }

    return 0;
}