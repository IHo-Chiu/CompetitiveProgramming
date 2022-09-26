#include <stdio.h>

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

void printInt(unsigned long int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

char buf[1000001];
int main()
{
    for (char *p = buf, *q = buf; (*p = gc()) != '.'; p = q = buf)
    {
        while ((*++p = gc()) != '\n')
        {
            if (*q != *p) q = buf;
            if (*q == *p) q++;
        }
        printInt((p-buf)%(p-q) ? 1 : (p-buf)/(p-q));
        pc('\n');
    }
    return 0;
}