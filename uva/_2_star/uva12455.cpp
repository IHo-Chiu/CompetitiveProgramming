# include <stdio.h>
# include <memory.h>

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int t, n, p;
        scanf("%d %d", &t, &n);

        bool tArr[n][t+1];
        memset(tArr, 0, sizeof(tArr));
        tArr[0][0] = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p);
            if (i == 0)
            {
                tArr[0][p] = true;
                continue;
            }
            for (int j = 0; j <= t; j++)
                if (tArr[i-1][j]) {
                    tArr[i][j] = true;
                    if (j+p <= t)
                        tArr[i][j+p] = true;
                }
        }

        if (tArr[n-1][t])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}