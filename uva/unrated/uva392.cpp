#include <stdio.h>

int main()
{
    int arr[9];
    bool isFirst;
    while (scanf("%d", &arr[0]) != EOF)
    {
        for (int i = 1; i < 9; i++)
            scanf("%d", &arr[i]);

        isFirst = true;
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == 0)
            {
                if (i == 8 && isFirst)
                {
                    printf("0");
                    break;
                }
                continue;
            }
            if (isFirst)
            {
                isFirst = false;
                if (arr[i] < 0)
                    printf("-");
            }
            else 
            {
                if (arr[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            if (arr[i] > 1)
                printf("%d", arr[i]);
            else if (arr[i] < -1)
                printf("%d", -arr[i]);
            else if (i == 8 && arr[i] == 1)
                printf("%d", arr[i]);
            else if (i == 8 && arr[i] == -1)
                printf("%d", -arr[i]);

            if (i == 7)
                printf("x");
            else if (i == 8)
                continue;
            else
                printf("x^%d", 8-i);
        }
        printf("\n");
    }

    return 0;
}