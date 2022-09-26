#include <stdio.h>

int main()
{
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF && !(a == 0 && b == 0 && c == 0 && d == 0))
    {
        printf("%d\n", (((a-b+40)%40) + ((c-b+40)%40) + ((c-d+40)%40))*9 + 1080);
    }

    return 0;
}