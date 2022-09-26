#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[1000];
    int len;
    int odd, even;
    while (scanf("%s", str) != EOF)
    {
        len = strlen(str);
        odd = even = 0;
        if (len == 1 && str[0] == '0')
            break;

        for (int i = 0;i < len; i++)
        {
            if (i%2) odd += str[i]-'0';
            else even += str[i]-'0';
        }

        printf("%s is ", str);
        if (abs(odd - even)%11 != 0)
            printf("not ");
        printf("a multiple of 11.\n");
    }

    return 0;
}