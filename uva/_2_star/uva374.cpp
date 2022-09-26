#include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc getchar_unlocked
#define pc putchar_unlocked

int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) < '0')
        if (ch == EOF)
            return -1;
    for (;ch >= '0'; ch = gc())
        x = x * 10 + ch - '0';
    
    return x;
}

void printInt(unsigned int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

int main()
{
    int B, P, M, T, mask, ans;
    while (1)
    {
        B = scanInt();
        if (B == -1) break;
        P = scanInt();
        M = scanInt();

        mask = ans = 1;
        for (T = P; T > 1; T >>= 1)
            mask <<= 1;
        T = B%M;
        for (; mask > 0; mask >>= 1)
        {
            ans = (ans*ans)%M;
            if (P & mask) ans = (ans*T)%M;
        }

        printInt(ans);
        pc('\n');
    }

    return 0;
}