#include <stdio.h>

int main()
{
    int q, n, cnt;
    char farm[100];
    scanf("%d", &q);
    for (int qq = 1; qq <= q; qq++)
    {
        scanf("%d", &n);
        scanf("%s", farm);

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (farm[i] == '.')
            {
                cnt++;
                i += 2;
            }
        }

        printf("Case %d: %d\n", qq, cnt);
    }

    return 0;
}