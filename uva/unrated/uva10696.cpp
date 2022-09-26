#include <stdio.h>

int f91(int N)
{
    if (N >= 101) return N-10;
    else return f91(f91(N+11));
}

int main()
{
    int a;
    while (scanf("%d", &a) != EOF && a != 0)
    {
        printf("f91(%d) = %d\n", a, f91(a));
    }

    return 0;
}