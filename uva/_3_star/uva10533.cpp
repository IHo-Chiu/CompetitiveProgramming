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

#define SIEVE_LIST_SIZE 1000000
#define PRIME_LIST_SIZE 30125

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

void SieveOfEratosthenes();
bool isprime(int x);
bool isDigitPrime(int x);
int binarySearch(int x);

// Sieve of Eratosthenes
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
            if (isDigitPrime(ii))
                prime[primeCount++] = ii;

            for (j=N2I(SIEVE_LIST_SIZE/ii), k=ii*j+i; j>=i; j--, k-=ii)
                if (!GET(j))
                    SET(k);
        }

    for (; i < SIEVE_LIST_SIZE >> 1; i++)
        if (!GET(i))
        {
            ii=I2N(i);
            if (isDigitPrime(ii))
                prime[primeCount++] = ii;
        }
            
}

bool isprime(int x)
{
    return x==2 || x>2 && (x&1) && !GET(N2I(x));
}

bool isDigitPrime(int x)
{
    register int sum = 0;
    while (x > 0) {
        sum += x%10;
        x /= 10;
    }

    return isprime(sum);
}

int isFoundFlag = 0;
int binarySearch(int x)
{
    isFoundFlag = 0;
    if (x == 1)
        return 0;

    register int left = 0;
    register int right = primeCount;
    register int mid = primeCount >> 1;
    while (1)
    {
        if (prime[mid] == x)
        {
            isFoundFlag = 1;
            return mid;
        }

        if (mid == left)
            return mid+1;

        if (prime[mid] > x)
            right = mid;
        else
            left = mid;

        mid = (left + right) >> 1;
    }
}

int main()
{
    SieveOfEratosthenes();

    int t1, t2;
    while (gc() != '\n')
        ;

    while (t1 = scanInt())
    {
        t2 = scanInt();
        printUInt(binarySearch(t2) + isFoundFlag - binarySearch(t1));
        pc('\n');
    }

    return 0;
}