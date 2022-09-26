#include <stdio.h>
#include <string.h>

int main()
{
    int qNum;
    scanf("%d", &qNum);
    while (qNum--)
    {
        char str[6];
        scanf("%s", str);
        if (strlen(str) == 5)
        {
            printf("3\n");
        }
        else
        {
            int cnt = 0;
            if (str[0] == 'o')
                cnt++;
            if (str[1] == 'n')
                cnt++;
            if (str[2] == 'e')
                cnt++;
            if (cnt >= 2)
                printf("1\n");
            else
                printf("2\n");
        }
    }

    return 0;
}