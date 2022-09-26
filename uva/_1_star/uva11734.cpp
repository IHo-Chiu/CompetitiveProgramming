#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while (getchar() !='\n')
        ;

    char team[100];
    char judge[100];
    char *p, *p1, *p2;
    for (int i = 1; i <= q; i++)
    {
        bool isFormatError = false;
        bool isWrongAnswer = false;
        for (p = team; (*p = getchar()) != '\n'; p++)
            ;
        *p = '\0';
        for (p = judge; (*p = getchar()) != '\n' && *p != EOF; p++)
            ;
        *p = '\0';

        for (p1 = team, p2 = judge; *p1 != '\0' || *p2 != '\0';)
        {
            if (*p1 == *p2)
            {
                if (*p1 != '\0') p1++;
                if (*p2 != '\0') p2++;
            }
            else if (*p1 == ' ')
                p1++, isFormatError = true;
            else {
                isWrongAnswer = true;
                break;
            }
        }

        if (isWrongAnswer)
            printf("Case %d: Wrong Answer\n", i);
        else if (isFormatError)
            printf("Case %d: Output Format Error\n", i);
        else
            printf("Case %d: Yes\n", i);
    }

    return 0;
}