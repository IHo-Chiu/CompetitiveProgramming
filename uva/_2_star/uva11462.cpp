#include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
//#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<15], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
	return *p++;
}

unsigned char scanIntShort()
{
    register char ch;
    register unsigned char x;
    if ((ch = gc()) == EOF)
        return 0;
    x = ch - '0';
    if ((ch = gc()) >= '0')
    {
        gc();
        return x * 10 + ch - '0';
    }
    
    return x;
}

unsigned int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

char str[10000000];
char *top;

void printInt(unsigned char n) {
    if (n>9) *top++ = n/10 + '0';
    *top++ = (n%10) + '0';
}

int main()
{
    int i;
    int arr[100] = {0};
    while (i = scanInt())
    {
        top = str;
        while (i--) arr[scanIntShort()]++;
        for (i = 1; i < 100; i++)
            for (;arr[i]; arr[i]--)
                printInt(i), *top++ = ' ';
        *top = '\0';
        puts(str);
    }

    return 0;
}