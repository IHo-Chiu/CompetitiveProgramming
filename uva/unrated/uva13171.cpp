# include <stdio.h>

int main()
{
    int q, m, y, c;
    char ch = '\0';
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &m, &y, &c);
        
        while ((ch = getchar()) != '\n')
        {
            switch (ch)
            {
                case 'M': m--; break;
                case 'Y': y--; break;
                case 'C': c--; break;
                case 'R': m--; y--; break;
                case 'B': m--; y--; c--; break;
                case 'G': y--; c--; break;
                case 'V': m--; c--; break;
            }
        }

        if (m >= 0 && y >= 0 && c >= 0)
            printf("YES %d %d %d\n", m, y, c);
        else
            printf("NO\n");

    }

    return 0;
}