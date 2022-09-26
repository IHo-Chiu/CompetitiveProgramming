#include <stdio.h>
#include <math.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<15], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
	return *p++;
}

long scanInt()
{
    register char ch;
    register long x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

inline void abundant() { pc('a'),pc('b'),pc('u'),pc('n'),pc('d'),pc('a'),pc('n'),pc('t'),pc('\n');}
inline void deficient() { pc('d'),pc('e'),pc('f'),pc('i'),pc('c'),pc('i'),pc('e'),pc('n'),pc('t'),pc('\n');}
inline void perfect() { pc('p'),pc('e'),pc('r'),pc('f'),pc('e'),pc('c'),pc('t'),pc('\n');}

#define SIEVE_LIST_SIZE 999984
#define PRIME_LIST_SIZE 78498

// Sieve of Eratosthenes
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
int prime[PRIME_LIST_SIZE+1] = {2};
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
    scanInt();
    long x, input, sum, a, p;
    while ((input = scanInt()) > 0)
    {
        x = input;
        sum = 1;
        for (int i = 0, p = prime[0]; i < primeCount && x > 1 && p*p <= x; i++, p = prime[i]) {
            if (x%p) continue;
            a = p;
            while (x%p == 0)
                a *= p, x /= p;
            sum *= (a-1)/(p-1);
        }

        if (x == input) {
            deficient();
            continue;
        }

        if (x > 1) sum *= x+1;
        sum -= input;

        if (sum > input) abundant();
        else if (sum < input) deficient();
        else perfect();
    }

    return 0;
}
