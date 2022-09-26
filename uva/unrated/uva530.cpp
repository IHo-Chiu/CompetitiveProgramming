# include <stdio.h>

int main()
{
    int N, M;
    long int C;
    while (scanf("%d %d", &N, &M) != EOF && N > 0)
    {
        if (N-M > M)
            M = N-M;
        
        C = 1;
        for (int i = N, j = 1; i > M; i--, j++)
        {
            C *= i;
            C /= j;
        }

        printf("%ld\n", C);
    }

    return 0;
}