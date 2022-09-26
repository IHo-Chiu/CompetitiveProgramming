#include <stdio.h>

int main()
{
    long long int n, k, ans;
    while (scanf("%lld %lld", &n, &k) != EOF)
    {
        ans = n;
        while (n >= k)
        {
            ans += n/k;
            n = n%k + n/k;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
