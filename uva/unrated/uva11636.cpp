#include <stdio.h>

int main()
{
    int q = 0, n, cnt;
    while (scanf("%d", &n) != EOF && n > 0)
    {
        for (cnt = 0, n--; n > 0; n >>= 1)
            cnt++;
            
        printf("Case %d: %d\n", ++q, cnt);
    }

    return 0;
}