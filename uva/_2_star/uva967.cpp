#include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

int list[42] = {113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};

int main()
{
    int a, b;
    register int cnt, i;
    while (scanf("%d", &a) && a != -1)
    {
        scanf("%d", &b);
        cnt = 0;
        for (i = 0; i < 42; i++)
            if (list[i] >= a && list[i] <= b)
                cnt++;
            else if (list[i] > b)
                break;

        switch (cnt)
        {
            case 0: printf("No Circular Primes.\n"); break;
            case 1: printf("1 Circular Prime.\n"); break;
            default : printf("%d Circular Primes.\n", cnt); break;
        }
    }

    return 0;
}