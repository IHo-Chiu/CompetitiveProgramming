#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

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

#define SIEVE_LIST_SIZE 1299710

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

// Sieve of Eratosthenes
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
inline int  GET(int x) { return sieve[x>>5]>>(x&31) & 1; }
inline void SET(int x) { sieve[x>>5] |= 1<<(x&31); }
inline int  N2I(int i) { return (i-1)>>1; }
inline int  I2N(int i) { return (i<<1)+1; }
void SieveOfEratosthenes()
{
    int half_sqrt_N = (int) sqrt(SIEVE_LIST_SIZE) >> 1;
    register int i, j, k, ii;
    for (i = 1; i <= half_sqrt_N; i++)
        if (!GET(i))
            for (ii=I2N(i), j=N2I(SIEVE_LIST_SIZE/ii), k=ii*j+i; j>=i; j--, k-=ii)
                if (!GET(j))
                    SET(k);
}

bool isprime(int x)
{
    return x==2 || x>2 && (x&1) && !GET(N2I(x));
}

int main()
{
    SieveOfEratosthenes();

    int a, index;
    while (a = scanInt())
    {
        if (isprime(a)) 
            pc('0'), pc('\n');
        else {
            register int i = a>>1;
            register int j = i-1;
            while (GET(i)) i++;
            while (GET(j)) j--;

            printUInt((i-j) << 1);
            pc('\n');
        }
    }

    return 0;
}