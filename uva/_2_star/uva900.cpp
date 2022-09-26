#include <stdio.h>

int main()
{
    long int F[51];
    F[0] = F[1] = 1;
    for (int i = 2; i < 51; i++)
        F[i] = F[i-1] + F[i-2];

    int x;
    while (scanf("%d", &x) != EOF && x > 0)
    {
        printf("%ld\n", F[x]);
    }

    return 0;
}