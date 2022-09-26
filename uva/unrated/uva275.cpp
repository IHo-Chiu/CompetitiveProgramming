#include <stdio.h>
#include <memory.h>

int main()
{
    int hash[1000];
    int numerator, denominator, seq;
    while (scanf("%d %d", &numerator, &denominator) != EOF)
    {
        if (numerator == 0 && denominator == 0)
            break;

        memset(hash, 0, sizeof(hash));
        putchar_unlocked('.');
        for (seq = 1; hash[numerator] == 0 && numerator > 0; seq++)
        {
            hash[numerator] = seq;
            numerator *= 10;
            if (seq%50 == 0) putchar_unlocked('\n');
            putchar_unlocked(numerator/denominator + '0');
            numerator %= denominator;
        }

        if (numerator == 0)
            printf("\nThis expansion terminates.\n\n");
        if (hash[numerator] != 0)
            printf("\nThe last %d digits repeat forever.\n\n", seq-hash[numerator]);
    }

    return 0;
}