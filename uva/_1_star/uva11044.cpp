#include <stdio.h>

int main()
{
    int q, n, m;
    scanf("%d", &q);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        printf("%d\n", (n/3)*(m/3));
    }

    return 0;
}