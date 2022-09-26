#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

void printInt(int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

#define SIEVE_LIST_SIZE 999984
#define PRIME_LIST_SIZE 78497

// Sieve of Eratosthenes
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
int prime[PRIME_LIST_SIZE+1];
int primeCount = 0;
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

bool isprime(int x)
{
    return (x&1) && !GET(N2I(x));
}

int main()
{
    SieveOfEratosthenes();
    int n;
    while (n = scanInt())
    {
        for (int i = 0; i < primeCount; i++)
        {
            if ((prime[i]<<1) > n)
            {
                puts("Goldbach's conjecture is wrong.");
                break;
            }
            if (isprime(n-prime[i]))
            {
                printInt(n);
                pc(' '), pc('='), pc(' ');
                printInt(prime[i]);
                pc(' '), pc('+'), pc(' ');
                printInt(n-prime[i]);
                pc('\n');
                break;
            }
        }
    }

    return 0;
}