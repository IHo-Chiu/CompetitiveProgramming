#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (getchar() != '\n')
        ;

    for (int tt = 0; tt < T; tt++)
    {
        printf("Case #%d:\n", tt+1);

        char graph[50][50];
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                graph[i][j] = ' ';

        int chIdx = -1;
        int curHigh = 0;
        char ch = '\0';
        int maxHigh = 0;
        while ((ch = getchar()) != '\n')
        {
            chIdx++;
            if (ch == 'C')
            {
                graph[curHigh][chIdx] = '_';
                if (curHigh > maxHigh)
                    maxHigh = curHigh;
            }
            else if (ch == 'R')
            {
                graph[curHigh][chIdx] = '/';
                curHigh++;
                if (curHigh > maxHigh+1)
                    maxHigh = curHigh-1;
            }
            else if (ch == 'F')
            {
                curHigh--;
                if (curHigh == -1)
                {
                    for (int i = 0; i < chIdx; i++)
                    {
                        for (int j = maxHigh; j >= 0; j--)
                        {
                            graph[j+1][i] = graph[j][i];
                            graph[j][i] = ' ';
                        }
                    }
                    if (chIdx > 0)
                        maxHigh++;
                    curHigh = 0;
                }
                graph[curHigh][chIdx] = '\\';
            }
        }

        for (int i = maxHigh; i >= 0; i--)
        {
            for (int j = 49; j >= 0; j--)
            {
                if (graph[i][j] == ' ')
                    graph[i][j] = '\0';
                else
                    break;
            }
        }

        for (int i = maxHigh; i >= 0; i--)
        {
            putchar('|');
            putchar(' ');
            for (int j = 0; j <= chIdx; j++)
            {
                if (graph[i][j] == '\0')
                    break;
                putchar(graph[i][j]);
            }
            putchar('\n');
        }
        putchar('+');
        putchar('-');
        for (int j = 0; j <= chIdx; j++)
        {
            putchar('-');
        }
        putchar('-');
        putchar('\n');
        putchar('\n');
    }

    return 0;
}