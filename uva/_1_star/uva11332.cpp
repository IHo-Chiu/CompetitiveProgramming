#include <stdio.h>

int main()
{
    int n, g;
    while (scanf("%d", &n) != EOF && n > 0)
    {
        do
        {
            g = 0;
            while (n > 0)
            {
                g += n%10;
                n /= 10;
            }
            n = g;
        } while (n >= 10);

        printf("%d\n", g);
    }

    return 0;
}