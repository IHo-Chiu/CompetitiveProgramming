# include <stdio.h>
# include <math.h>

int main()
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        long long int poly[N+1];
        for (int i = 0; i < N+1; i++)
            poly[i] = 0;

        poly[0] = 1;

        int a;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a);

            for (int j = i+1; j > 0; j--)
                poly[j] = -a*poly[j] + poly[j-1];

            poly[0] *= -a;
        }

        for (int i = N; i >= 0; i--)
        {
            if (i != N)
            {
                if (poly[i] > 0)
                    printf(" + ");
                else if (poly[i] < 0)
                    printf(" - ");
            }

            if (abs(poly[i]) > 1)
            {
                printf("%lld", abs(poly[i]));
            }
            else if (abs(poly[i]) == 1)
            {
                if (i == 0)
                    printf("1");
            }
            else if (poly[i] == 0)
            {
                if (i == 0)
                    printf(" + 0");

                continue;
            }

            if (i > 1)
                printf("x^%d", i);
            else if (i == 1)
                printf("x");
        }
        printf(" = 0\n");
    }

    return 0;
}