# include <stdio.h>

int main()
{
    char *ch;
    char buffer[8];
    buffer[7] = '\0';
    int baseBefore, baseAfter, num;
    while (scanf("%s %d %d", buffer, &baseBefore, &baseAfter) != EOF)
    {
        num = 0;
        for (ch = buffer; *ch != '\0'; ch++)
        {
            num *= baseBefore;
            num += (*ch >= 'A') ? *ch - 55 : *ch - 48;
        }

        if (num)
        {
            for (ch = buffer+6; ch >= buffer; ch--)
            {
                if (num)
                {
                    *ch = num % baseAfter;
                    *ch += (*ch > 9) ? 55 : 48;
                }
                else *ch = ' ';

                num /= baseAfter;
            }

            if (num) printf("  ERROR\n");
            else printf("%s\n", buffer);
        }
        else printf("      0\n");
    }

    return 0;
}
