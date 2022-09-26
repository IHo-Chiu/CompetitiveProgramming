# include <stdio.h>

int main()
{
    int q, a, b, c, d, ans;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a+b == c+d)
            ans = c - a;
        else
            ans = (c+d)-(a+b) + b + c + ((a+b+1)+(c+d-1))*((c+d)-(a+b+1))/2;

        printf("Case %d: %d\n", i+1, ans);
    }

    return 0;
}