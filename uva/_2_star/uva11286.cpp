#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

#define max(a, b) (a > b ? a : b)

char ch;
unsigned int scanInt()
{
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printUInt(unsigned int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

int main()
{
    int n = scanInt();
    int arr1[21];
    int arr2[21];
    int LCS[21][21];

    for (int i = 0; i < 21; i++)
    {
        LCS[0][i] = 0;
        LCS[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
        arr1[scanInt()] = i;

    while (1)
    {
        arr2[scanInt()] = 1;
        if (ch == EOF)
            break;

        for (int i = 2; i <= n; i++)
            arr2[scanInt()] = i;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (arr1[i] == arr2[j])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);

        printUInt(LCS[n][n]);
        pc('\n');
    }

    return 0;
}