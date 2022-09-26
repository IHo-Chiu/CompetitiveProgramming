#include <stdio.h>
#include <math.h>

#define SIEVE_LIST_SIZE 1001
#define PRIME_LIST_SIZE 1000

// Sieve of Eratosthenes
int sieve[(SIEVE_LIST_SIZE>>6) + 1];
int prime[PRIME_LIST_SIZE+1] = {1, 2};
int primeCount = 2;
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
    prime[primeCount] = SIEVE_LIST_SIZE;

    int N, C, K;
    int start, end, count;
    while (scanf("%d %d", &N, &C) != EOF)
    {
        for (int i = 0; i <= primeCount; i++)
            if (prime[i] > N) {
                K = i;
                break;
            }
        count = C*2 - (K&1);
        if (count >= K) {
            start = 0;
            end = K;
        } else {
            start = K/2 - count/2;
            end = start + count;
        }
        printf("%d %d:", N, C);
        for (int i = start; i < end; i++)
            printf(" %d", prime[i]);
        printf("\n\n");
    }

    return 0;
}
