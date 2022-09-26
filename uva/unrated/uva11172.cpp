#include <stdio.h>

int main()
{
    int q;
    long long int a, b;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld %lld", &a, &b);
        if (a > b) printf(">\n");
        else if (a < b) printf("<\n");
        else printf("=\n");
    }

    return 0;
}