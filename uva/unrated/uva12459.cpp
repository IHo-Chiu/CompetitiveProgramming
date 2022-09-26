#include <stdio.h>

int main()
{
    int n;

    long long int F[81];
    F[0] = F[1] = 1;
    for (int i = 2; i <= 80; i++)
        F[i] = F[i-1] + F[i-2];

    while (scanf("%d", &n) != EOF && n > 0)
    {
        printf("%lld\n", F[n]);
    }

    return 0;
}