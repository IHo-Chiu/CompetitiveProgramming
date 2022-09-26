#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    while (scanf("%s", str) != EOF && str[0] != '-')
    {
        if (str[0] == '0' && strlen(str) > 1)
        {
            int ans = 0;
            for (int i = 2; i < strlen(str); i++)
                if ('A' <= str[i] && str[i] <= 'F')
                    ans = ans*16 + str[i]-'A'+10;
                else if ('0' <= str[i] && str[i] <= '9')
                    ans = ans*16 + str[i]-'0';
            printf("%d\n", ans);
        }
        else
        {
            int ans = 0;
            for (int i = 0; i < strlen(str); i++)
                ans = ans*10 + str[i]-'0';

            int out[100];
            char size = 0;
            for (; ans > 0; ans /= 16)
                out[size++] = ans%16;

            printf("0x");
            for (int i = size-1; i >= 0; i--)
                if (out[i] >= 10)
                    printf("%c", out[i]-10+'A');
                else
                    printf("%c", out[i]+'0');
            printf("\n");
        }   
    }

    return 0;
}