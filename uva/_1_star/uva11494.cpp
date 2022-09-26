#include <stdio.h>

int main()
{
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0)
            break;

        if (a == c && b == d)
            printf("0\n");
        else if (a == c || b == d || a+b == c+d || a-b == c-d)
            printf("1\n");
        else
            printf("2\n");
    }

    return 0;
}