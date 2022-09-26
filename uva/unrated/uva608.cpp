#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int q;
    scanf("%d", &q);

    int coin[12];
    char left[7], right[7], status[5];
    while (q--)
    {
        memset(coin, 0, sizeof(coin));
        for (int i = 0; i < 3; i++)
        {
            scanf("%s %s %s", left, right, status);
            //printf("%s %s %s\n", left, right, status);

            if (strcmp(status, "even") == 0)
            {
                for (int j = 0; j < strlen(left); j++)
                    coin[left[j]-'A'] = coin[right[j]-'A'] = 1;
            }
            else if (strcmp(status, "up") == 0)
            {
                for (int j = 0; j < strlen(left); j++)
                {
                    if (coin[left[j]-'A'] == 0)
                        coin[left[j]-'A'] = 2;
                    else if (coin[left[j]-'A'] == 3)
                        coin[left[j]-'A'] = 1;
                    if (coin[right[j]-'A'] == 0)
                        coin[right[j]-'A'] = 3;
                    else if (coin[right[j]-'A'] == 2)
                        coin[right[j]-'A'] = 1;
                }

                for (int j = 0; j < 12; j++)
                {
                    bool isEven = true;
                    for (int k = 0; k < strlen(left); k++)
                        if (j == left[k]-'A' || j == right[k]-'A')
                        {
                            isEven = false;
                            break;
                        }
                    if (isEven)
                        coin[j] = 1;
                }
            }
            else if (strcmp(status, "down") == 0)
            {
                for (int j = 0; j < strlen(left); j++)
                {
                    if (coin[left[j]-'A'] == 0)
                        coin[left[j]-'A'] = 3;
                    else if (coin[left[j]-'A'] == 2)
                        coin[left[j]-'A'] = 1;
                    if (coin[right[j]-'A'] == 0)
                        coin[right[j]-'A'] = 2;
                    else if (coin[right[j]-'A'] == 3)
                        coin[right[j]-'A'] = 1;
                }

                for (int j = 0; j < 12; j++)
                {
                    bool isEven = true;
                    for (int k = 0; k < strlen(left); k++)
                        if (j == left[k]-'A' || j == right[k]-'A')
                        {
                            isEven = false;
                            break;
                        }
                    if (isEven)
                        coin[j] = 1;
                }
            }
        }

        for (int i = 0; i < 12; i++)
            if (coin[i] != 1)
            {
                printf("%c is the counterfeit coin and it is ", i+'A');
                if (coin[i] == 3)
                    printf("light.\n");
                else if (coin[i] == 2)
                    printf("heavy.\n");
            }
    }

    return 0;
}