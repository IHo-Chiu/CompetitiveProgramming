#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int days;
        scanf("%d", &days);

        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        bool calander[days+1];
        for (int i = 0; i <= days; i++)
            calander[i] = false;

        for (int i = 0; i < n; i++)
        {
            int shift = arr[i];
            for (int j = shift; j <= days; j += shift)
            {
                calander[j] = true;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= days; i++)
        {
            if ((i-1)%7 == 5 || (i-1)%7 == 6)
                continue;
            if (calander[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
