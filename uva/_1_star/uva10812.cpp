#include <stdio.h>

int main()
{
    int q, a, b, x, y;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &a, &b);
        x = a+b;
        y = a-b;
        if (y < 0 || y & 1)
            printf("impossible\n");
        else
            printf("%d %d\n", x>>1, y>>1);
    }

    return 0;
}