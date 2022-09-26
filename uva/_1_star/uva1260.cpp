# include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);

    for (int qq; qq < q; qq++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int ans = 0;
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
                if (i != j && arr[i] <= arr[j])
                    ans++;

        printf("%d\n", ans);
    }
    return 0;
}
