#include <stdio.h>
#include <math.h>

int main()
{
    long a, b;
    while (scanf("%ld %ld", &a, &b) != EOF)
        printf("%ld\n", abs(a-b));

    return 0;
}