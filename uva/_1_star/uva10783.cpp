#include <stdio.h>

int main ()
{
    int q, a, b, s;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d %d", &a, &b);
        s = 0;
        for (int j = a; j <= b; j++)
        {
            if (j%2 == 1)
                s += j;
        }

        printf("Case %d: %d\n", i, s);
    }

    return 0;
}