#include <stdio.h>
#include <memory.h>

int main()
{
    char str[100][100];
    memset(str, ' ', sizeof(str));
    int size = 0;
    int max_len = 0;
    char *cur = str[0];
    char ch;
    while ((ch = getchar_unlocked()) != EOF)
    {
        if (ch == '\n')
        {
            if (cur - str[size] > max_len)
                max_len = cur - str[size];
            cur = str[++size];
        }
        else *cur++ = ch;
    }

    for (int i = 0; i < max_len; i++)
    {
        for (int j = size-1; j >= 0; j--)
            putchar_unlocked(str[j][i]);
        putchar_unlocked('\n');
    }

    return 0;
}