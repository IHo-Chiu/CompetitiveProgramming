#include <stdio.h>

int main()
{
    unsigned int F[46];
    F[0] = 0, F[1] = 1;
    for (int i = 2; i < 46; i++)
        F[i] = F[i-1] + F[i-2];
    for (int i = 1; i < 46; i++)
        F[i] += F[i-1];

    int n;
    while (scanf("%d", &n) != EOF && n >= 0)
    {
        printf("%u %u\n", F[n], F[n+1]);
    }

    return 0;
}