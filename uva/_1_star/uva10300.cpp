#include <stdio.h>

int main()
{
    int q, n;
    long int a, b, c;
    long int total;
    scanf("%d", &q);
    while (q--)
    {
        total = 0;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%ld %ld %ld", &a, &b, &c);
            total += a*c;
        }

        printf("%ld\n", total);
    }

    return 0;
}