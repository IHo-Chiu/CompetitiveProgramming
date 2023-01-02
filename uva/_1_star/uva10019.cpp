#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);

    while (q--)
    {
        int N;
        scanf("%d", &N);

        int D = N;
        int cnt = 0;
        while (D)
        {
            cnt += D%2;
            D /= 2;
        }

        printf("%d ", cnt);

        int H = 0;
        while (N)
        {
            H = H*16 + N%10;
            N /= 10;
        }

        cnt = 0;
        while (H)
        {
            cnt += H%2;
            H /= 2;
        }

        printf("%d\n", cnt);

    }

    return 0;
}