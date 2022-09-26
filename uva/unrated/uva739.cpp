#include <stdio.h>
#include <string.h>

int main()
{
    char str[21];
    char soundex[21];
    int soundexTop, soundexLast;
    char group[7][9] = 
    {
        {'A','E','I','O','U','Y','W','H','\0'},
        {'B','P','F','V','\0'},
        {'C','S','K','G','J','Q','X','Z','\0'},
        {'D','T','\0'},
        {'L','\0'},
        {'M','N','\0'},
        {'R','\0'}
    };
    printf("         NAME                     SOUNDEX CODE\n");
    while (scanf("%s", str) != EOF)
    {
        soundex[0] = soundex[1] = soundex[2] = soundex[3] = '0';
        soundex[4] = '\0';
        soundexTop = soundexLast = -1;
        for (int i = 0; i < strlen(str); i++)
            for (int j = 0; j < 7; j++)
                for (int k = 0; group[j][k] != '\0'; k++)
                    if (group[j][k] == str[i])
                        if (soundexLast != j)
                        {
                            soundexLast = j;
                            if (soundexLast != 0 || i == 0)
                                soundex[++soundexTop] = soundexLast+'0';
                        }
        soundex[0] = str[0];
        soundex[4] = '\0';
        printf("         %-25s%s\n", str, soundex);
    }

    printf("                   END OF OUTPUT\n");

    return 0;
}