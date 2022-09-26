#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

int scanInt()
{
    register char ch;
    register int x = 0;
    bool neg = false;

    if ((ch = gc()) == '-')
        neg = true;
    else x = ch - '0';

    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';

    while (ch != '\n' && ch != EOF)
        ch = gc();

    if (neg) return -x;
    else return x;
}

void printUInt(unsigned int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}
void printInt(int n) {
    if (n<0) {
        pc('-');
        printUInt(-n);
    }
    else printUInt(n);
}

#define SIEVE_LIST_SIZE 46338
#define PRIME_LIST_SIZE 4792

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

// Sieve of Eratosthenes // https://web.ntnu.edu.tw/~algo/Prime.html
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
int prime[PRIME_LIST_SIZE] = {2};
int primeCount = 1;
inline int  GET(int x) { return sieve[x>>5]>>(x&31) & 1; }
inline void SET(int x) { sieve[x>>5] |= 1<<(x&31); }
inline int  N2I(int i) { return (i-1)>>1; }
inline int  I2N(int i) { return (i<<1)+1; }

void SieveOfEratosthenes()
{
    int half_sqrt_N = (int) sqrt(SIEVE_LIST_SIZE) >> 1;
    register int i, j, k, ii;
    for (i = 1; i <= half_sqrt_N; i++)
        if (!GET(i)) {
            ii=I2N(i);
            prime[primeCount++] = ii;
            for (j=N2I(SIEVE_LIST_SIZE/ii), k=ii*j+i; j>=i; j--, k-=ii)
                if (!GET(j))
                    SET(k);
        }

    for (; i < SIEVE_LIST_SIZE >> 1; i++)
        if (!GET(i))
            prime[primeCount++] = I2N(i);
}

int main()
{
    SieveOfEratosthenes();

    int n;
    bool isFirst;
    while (n = scanInt())
    {
        isFirst = true;
        printInt(n);
        pc(' '), pc('='), pc(' ');

        if (n == 1)
        {
            pc('1'), pc('\n');
            continue;
        }
        if (n == -1)
        {
            pc('-'), pc('1'), pc('\n');
            continue;
        }
        if (n == 0)
        {
            pc('0'), pc('\n');
            continue;
        }
        if (n < 0)
        {
            pc('-'), pc('1');
            n = -n;
            isFirst = false;
        }

        for (int i = 0; i < PRIME_LIST_SIZE && n > 1; i++)
            while (n%prime[i] == 0)
            {
                if (isFirst) isFirst = false;
                else pc(' '), pc('x'), pc(' ');
                printUInt(prime[i]);
                n /= prime[i];
            }

        if (n > 1)
        {
            if (!isFirst) pc(' '), pc('x'), pc(' ');
            printUInt(n);
        }

        pc('\n');
    }

    return 0;
}