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

char ch = '\0';
long scanInt()
{
    register long x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printInt(int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

#define SIEVE_LIST_SIZE 32767
#define PRIME_LIST_SIZE 43

void SieveOfEratosthenes();
bool isprime(int x);
bool isDigitPrime(int x);
int binarySearch(int x);

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
}
bool isprime(int x)
{
    return x==2 || x>2 && (x&1) && !GET(N2I(x));
}

int main()
{
    SieveOfEratosthenes();

    int X, a, n;
    bool done_flag = false;
    int primeValue[100];
    int primeValueCount[100];
    int top;
    while (!done_flag)
    {
        X = 1;
        ch = '\0';
        top = -1;
        while (ch != '\n')
        {
            a = scanInt();
            if (a == 0)
            {
                done_flag = true;
                break;
            }
            n = scanInt();
            while (n--)
                X *= a;
        }

        if (done_flag)
            break;

        X--;
        if (isprime(X))
        {
            printInt(X);
            pc(' ');
            pc('1');
            pc('\n');
            continue;
        }

        for (int i = primeCount-1; i >= 0; i--)
        {
            if (X == 1)
                break;
            if (X < prime[i])
                continue;
            
            int cnt = 0;
            while (X%prime[i] == 0)
            {
                X /= prime[i];
                cnt++;
            }

            if (cnt)
            {
                top++;
                primeValue[top] = prime[i];
                primeValueCount[top] = cnt;
            }
        }

        bool isFirst = true;
        if (X > 1)
        {
            printInt(X);
            pc(' ');
            pc('1');
            isFirst = false;
        }
        for (int i = 0; i <= top; i++)
        {
            if (isFirst) isFirst = false;
            else pc(' ');
            printInt(primeValue[i]);
            pc(' ');
            printInt(primeValueCount[i]);
        }
        pc('\n');
    }

    return 0;
}
