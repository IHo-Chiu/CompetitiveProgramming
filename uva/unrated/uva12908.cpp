# include <stdio.h>
# include <math.h>


/*

    (1+n)*n/2 - k = a
    (a+k)*2 = n+n^2
    n^2 + n - a*2 - k*2 = 0
    a*2 = n^2 + n - k*2

    1 <= k <= n
    2 <= k*2 <= n*2
    n^2 + n - 2 >= a*2 >= n^2 - n
    
    (n+2)(n-1) >= a*2 >= n(n-1)
    k = (1+n)*n/2 - a

*/

int main()
{
    long int a = 0;
    while (scanf("%ld", &a) != EOF && a != 0)
    {
        long int n = (long int) sqrt(a);
        while (!((n+2)*(n-1) >= a*2 && a*2 >= n*(n-1)))
            n++;
        
        long int k = (1+n)*n/2 - a;
        printf("%ld %ld\n", k, n);
    }

    return 0;
}