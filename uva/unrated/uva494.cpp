# include <stdio.h>
# include <ctype.h>

int main()
{
    char ch = '\0';
    int cnt = 0;
    bool isWord = false;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch)) 
        {
            isWord = true;
        }
        else
        {
            if (isWord)
            {
                cnt++;
                isWord = false;
            }
            
            if (ch == '\n')
            {
                printf("%d\n", cnt);
                cnt = 0;
            }
        }
    }

    return 0;
}