#include <stdio.h>

int main()
{
    int n, ans, zero_count, t;
    while (scanf("%d", &n) != EOF)
    {
        printf("%5d -> ", n);
        ans = 1;

        zero_count = 0;
        for (t = 5; t <= n; t *= 5)
            zero_count += n/t ;

        for (; n > 1; n--)
        {
            for (t = n; t%5 == 0; t /= 5)
                ;
            while (!(t&1) && zero_count)
            {
                t >>= 1;
                zero_count--;
            }

            ans *= t;
            while (ans%10 == 0)
                ans /= 10;
            ans %= 10;
        }

        printf("%d\n", ans);
    }

    return 0;
}