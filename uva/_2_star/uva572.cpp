#include <stdio.h>

int main()
{
    int m, n;
    char map[101][101];
    char stack[10000];
    int top;
    while (scanf("%d %d", &m, &n) != EOF && m > 0 && n > 0)
    {
        for (int i = 0; i < m; i++)
            scanf("%s", map[i]);

        int seq = 0;
        top = -1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == '*')
                    map[i][j] = 0;
                else if (map[i][j] == '@')
                {
                    if (i > 0 && j > 0 && map[i-1][j-1] > 0)
                        map[i][j] = map[i-1][j-1];
                    if (i > 0 && map[i-1][j] > 0) {
                        if (map[i][j] != '@')
                        {
                            if (map[i][j] != map[i-1][j])
                            {
                                stack[++top] = map[i][j];
                                stack[++top] = map[i-1][j];
                            }
                        }
                        else map[i][j] = map[i-1][j];
                    }
                    if (i > 0 && j+1 < n && map[i-1][j+1] > 0)
                    {
                        if (map[i][j] != '@')
                        {
                            if (map[i][j] != map[i-1][j+1])
                            {
                                stack[++top] = map[i][j];
                                stack[++top] = map[i-1][j+1];
                            }
                        }
                        else map[i][j] = map[i-1][j+1];
                    }
                    if (j > 0 && map[i][j-1] > 0)
                    {
                        if (map[i][j] != '@')
                        {
                            if (map[i][j] != map[i][j-1])
                            {
                                stack[++top] = map[i][j];
                                stack[++top] = map[i][j-1];
                            }
                        }
                        else map[i][j] = map[i][j-1];
                    }
                    
                    if (map[i][j] == '@')
                        map[i][j] = ++seq;
                }
            }

        seq++;
        int hash[seq];
        for (int i = 0; i < seq; i++)
            hash[i] = 0;
        
        for (int i = 0; i <= top; i+=2)
        {
            if (hash[stack[i]] == 0 && hash[stack[i+1]] == 0)
            {
                hash[stack[i]] = stack[i];
                hash[stack[i+1]] = stack[i];
            }
            else if (hash[stack[i]] != 0 && hash[stack[i+1]] != 0)
            {
                int t = hash[stack[i+1]];
                for (int j = 0; j < seq; j++)
                    if (hash[j] == t)
                        hash[j] = hash[stack[i]];
            }
            else if (hash[stack[i]] != 0)
            {
                hash[stack[i+1]] = hash[stack[i]];
            }
            else if (hash[stack[i+1]] != 0)
            {
                hash[stack[i]] = hash[stack[i+1]];
            }
        }

        bool hash2[seq];
        for (int i = 0; i < seq; i++)
            hash2[i] = false;
        for (int i = 0; i < seq; i++)
            if (hash[i] > 0)
                hash2[hash[i]] = true;
        
        int cnt = 0;
        for (int i = 0; i < seq; i++)
        {
            if (hash[i])
                cnt++;
            if (hash2[i])
                cnt--;
        }
        
        printf("%d\n", seq-cnt-1);
    }

    return 0;
}