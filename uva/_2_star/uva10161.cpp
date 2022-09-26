# include <stdio.h>
# include <math.h>

int main()
{
    int N, sqrt_N, diff;
    while (scanf("%d", &N) != EOF && N > 0)
    {
        sqrt_N = sqrt(N);
        diff = N - sqrt_N*sqrt_N;
        
        if (diff == 0)
        {
            if (sqrt_N%2 == 0)
                printf("%d 1\n", sqrt_N);
            else
                printf("1 %d\n", sqrt_N);
        }
        else
        {
            sqrt_N++;
            if (diff > sqrt_N)
            {
                diff = sqrt_N*2 - diff;
                if (sqrt_N%2 == 0)
                    printf("%d %d\n", sqrt_N, diff);
                else
                    printf("%d %d\n", diff, sqrt_N);
            }
            else
            {
                if (sqrt_N%2 == 0)
                    printf("%d %d\n", diff, sqrt_N);
                else
                    printf("%d %d\n", sqrt_N, diff);
            }
        }
    }

    return 0;
}