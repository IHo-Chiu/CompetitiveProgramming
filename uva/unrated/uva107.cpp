#include <stdio.h>
#include <math.h>

/*

h : height
w : worker cat
nw: not worker cat
N : cats in hat
c : counts of cat

h(n) = h(n-1)/N+1
h(0) = 1
=> 
h(n) = (N+1)^n

w(n) = N^n
nw(n) = N^0 + N^1 + N^2 + ... + N^(n-1)
      = (N^n - 1)/(N - 1)
      = (w(n) - 1)/(N - 1)
*/

int main()
{
    long long int h, w, N, n, nw, c;

    while (scanf("%lld %lld", &h, &w) != EOF && !(h == 0 && w == 0))
    {
        if (h == 1 && w == 1)
        {
            printf("0 1\n");
            continue;
        }

        n = 1;
        while ( (long long int)(pow(pow(w,1.0/n)+1,n)+(1e-8)) != h)
            n++;

        N = (long long int)(pow(w,1.0/n)+(1e-8));

        if (N > 1)
            nw = (w-1)/(N-1);
        else 
            nw = n;

        c = (h-w)*(N+1)+w;

        printf("%lld %lld\n", nw, c);
    }

    return 0;
}