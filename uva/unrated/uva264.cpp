#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, t;
    while (scanf("%d", &n) != EOF)
    {
        k = sqrt(2*n);
        t = n - k*(k+1)/2;
        if (t > 0)
            k++;
        if (t <= 0)
            t = k+t;

        printf("TERM %d IS ", n);
        if (k%2) printf("%d/%d\n", k-t+1, t);
        else printf("%d/%d\n", t, k-t+1);
    }   

    return 0;
}