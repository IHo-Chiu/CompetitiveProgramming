#include <stdio.h>

int main()
{
    long long int q, cnt, num, rev, tmp;
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld", &num);

        cnt = 0;
        while (true) {
            rev = num%10;
            tmp = num/10;
            while (tmp > 0)
            {
                rev = rev*10 + (tmp%10);
                tmp /= 10;
            }
            if (num == rev && cnt > 0)
                break;
            num += rev;
            cnt++;
        }

        printf("%lld %lld\n", cnt, rev);
    }

    return 0;
}