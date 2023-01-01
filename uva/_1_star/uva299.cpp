# include <stdio.h>

# define SWAP(a,b,t) ((t) = (a), (a) = (b), (b) = (t))

int main()
{
    int q;
    scanf("%d", &q);

    while (q--)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int ans = 0;
        int t;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-1-i; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    SWAP(arr[j], arr[j+1], t);
                    ans++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}