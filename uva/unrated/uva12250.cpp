#include <stdio.h>
#include <string.h>

int main()
{
    char str[15];
    int caseNum = 0;
    while (scanf("%s", str) && str[0] != '#')
    {
        caseNum++;
        if (strcmp(str, "HELLO") == 0)
            printf("Case %d: ENGLISH\n", caseNum);
        else if (strcmp(str, "HOLA") == 0)
            printf("Case %d: SPANISH\n", caseNum);
        else if (strcmp(str, "HALLO") == 0)
            printf("Case %d: GERMAN\n", caseNum);
        else if (strcmp(str, "BONJOUR") == 0)
            printf("Case %d: FRENCH\n", caseNum);
        else if (strcmp(str, "CIAO") == 0)
            printf("Case %d: ITALIAN\n", caseNum);
        else if (strcmp(str, "ZDRAVSTVUJTE") == 0)
            printf("Case %d: RUSSIAN\n", caseNum);
        else
            printf("Case %d: UNKNOWN\n", caseNum);
    }

    return 0;
}