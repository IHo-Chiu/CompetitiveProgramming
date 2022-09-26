#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF && a != -1 && b != -1)
    {
        printf("%d\n", min((a-b+100)%100, (b-a+100)%100));
    }

    return 0;
}