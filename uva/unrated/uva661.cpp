#include <stdio.h>
#include <memory.h>

int main()
{
    int n, m, c;
    int arr[21];
    int operation;
    int cur_c, max_c;
    bool turn[21];
    int q = 0;
    while (scanf("%d %d %d", &n, &m, &c) != EOF)
    {
        if (n == 0 && m == 0 && c == 0)
            break;

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        cur_c = max_c = 0;
        memset(turn, 0, sizeof(turn));
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &operation);
            operation--;
            turn[operation] = !turn[operation];
            if (turn[operation]) {
                cur_c += arr[operation];
                if (cur_c > max_c)
                    max_c = cur_c;
            }
            else
                cur_c -= arr[operation];
        }

        printf("Sequence %d\n", ++q);
        if (max_c > c)
            printf("Fuse was blown.\n");
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max_c);
        }
        printf("\n");
    }

    return 0;
}