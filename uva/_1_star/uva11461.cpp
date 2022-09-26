#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, t, sq, cnt;
    while (scanf("%d %d", &a, &b) != EOF && a > 0)
    {
        cnt = 0;
        t = sqrt(a), sq = t*t;
        if (sq != a)
            t++, sq = t*t;
        for (; sq <= b; t++, sq = t*t)
            cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}