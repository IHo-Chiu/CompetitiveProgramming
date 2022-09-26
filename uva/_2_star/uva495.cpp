# include <stdio.h>
# include <memory.h>

int main()
{
    char F[5001][1046];
    int len[5001];
    memset(F,0,sizeof(F));
    memset(len,0,sizeof(len));
    F[0][0] = 0, len[0] = 1;
    F[1][0] = 1, len[1] = 1;
    for (int i = 2; i <= 5000; i++)
    {
        for (int j = 0; j < len[i-1]; j++)
        {
            F[i][j] += F[i-1][j] + F[i-2][j];
            if (F[i][j] >= 10)
            {
                F[i][j+1] += 1;
                F[i][j] -= 10;
            }
        }

        len[i] = len[i-1];
        if (F[i][len[i]] > 0)
            len[i]++;
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("The Fibonacci number for %d is ", n);
        for (int i = len[n]-1; i >= 0; i--)
        {
            putchar_unlocked(F[n][i]+'0');
        }
        putchar_unlocked('\n');
    }

    return 0;
}