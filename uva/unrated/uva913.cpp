#include <stdio.h>

int main()
{
    long int N;
    while (scanf("%ld", &N) != EOF)
    {
        N = (N+1)/2;
        N = N*N*6-9;
        printf("%ld\n", N);
    }

    return 0;
}