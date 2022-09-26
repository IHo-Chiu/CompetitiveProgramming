#include <stdio.h>

int main()
{
    long int a;
    while (scanf("%ld", &a) != EOF && a >= 0)
    {
        printf("%ld\n", (a+1)*a/2 + 1);
    }

    return 0;
}