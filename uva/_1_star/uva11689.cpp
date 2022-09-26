#include <stdio.h>

int main()
{
    int q,e,f,c;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d %d", &e, &f, &c);
        printf("%d\n", e+f ? (e+f-1)/(c-1) : 0);
    }

    return 0;
}