#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%10d%10d    ", a, b);
        if (gcd(a, b) == 1)
            printf("Good Choice\n\n");
        else
            printf("Bad Choice\n\n");
    }

    return 0;
}