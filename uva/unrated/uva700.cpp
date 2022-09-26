#include <stdio.h>

int main()
{
    int n, x0, q=0;
    int arr[21][3];
    while (scanf("%d", &n) != EOF && n > 0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &arr[i][j]);

        for (int i = 0; i < n; i++)
            arr[i][1] = arr[i][2]-arr[i][1];

        for (x0 = arr[0][0]; x0 < 10000; x0 += arr[0][1])
        {
            bool isPass = true;
            for (int i = 1; i < n; i++)
            {
                if (x0 < arr[i][0] || (x0 - arr[i][0]) % arr[i][1])
                {
                    isPass = false;
                    break;
                }
            }

            if (isPass)
                break;
        }

        //if (q) printf("\n");
        printf("Case #%d:\n", ++q);
        if (x0 >= 10000)
            printf("Unknown bugs detected.\n");
        else
            printf("The actual year is %d.\n", x0);

        printf("\n");
    }

    return 0;
}