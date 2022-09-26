#include <stdio.h>
#include <algorithm>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<15], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
	return *p++;
}

unsigned int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printUInt(long int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

int main()
{
    int q, r, ans2;
    long int ans;
    int s[2000000];

    q = scanInt();
    while (q--)
    {
        r = scanInt();
        for (int i = 0; i < r; i++)
            s[i] = scanInt();

        std::nth_element(s, s+(r>>1), s+r);

        ans = ans2 = 0;
        for (int i = 0; i < r>>1; i++)
        {   
            ans += s[r-i-1] - s[i];
            if (s[i] > ans2)
                ans2 = s[i];
        }

        printUInt(ans);
        pc(' ');
        if (r&1)
            printUInt(s[r>>1]);
        else
            printUInt(ans2);
        pc('\n');
    }

    return 0;
}