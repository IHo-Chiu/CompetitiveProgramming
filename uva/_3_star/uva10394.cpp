#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
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

void printUInt(unsigned int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

#define SIEVE_LIST_SIZE 18409202
#define PRIME_LIST_SIZE 100000

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

// Sieve of Eratosthenes // https://web.ntnu.edu.tw/~algo/Prime.html
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
int prime[PRIME_LIST_SIZE];
int primeCount = 1;
inline int  GET(int x) { return sieve[x>>5]>>(x&31) & 1; }
inline void SET(int x) { sieve[x>>5] |= 1<<(x&31); }
inline int  N2I(int i) { return (i-1)>>1; }
inline int  I2N(int i) { return (i<<1)+1; }

bool isprime(int x)
{
    return x==2 || x>2 && (x&1) && !GET(N2I(x));
}

void SieveOfEratosthenes()
{
    int half_sqrt_N = (int) sqrt(SIEVE_LIST_SIZE) >> 1;
    register int i, j, k, ii;
    for (i = 1; i <= half_sqrt_N; i++)
        if (!GET(i)) {
            ii=I2N(i);
            if (isprime(ii-2))
                prime[primeCount++] = ii;

            for (j=N2I(SIEVE_LIST_SIZE/ii), k=ii*j+i; j>=i; j--, k-=ii)
                if (!GET(j))
                    SET(k);
        }

    for (; i < SIEVE_LIST_SIZE >> 1; i++)
        if (!GET(i))
        {
            ii=I2N(i);
            if (isprime(ii-2))
                prime[primeCount++] = ii;
        }
            
}

int main()
{
    SieveOfEratosthenes();

    int S;
    while (S = scanInt())
    {
        S = prime[S];
        pc('(');
        printUInt(S-2);
        pc(',');
        pc(' ');
        printUInt(S);
        pc(')');
        pc('\n');
    }

    return 0;
}