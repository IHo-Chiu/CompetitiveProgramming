# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int testNum;
    scanf("%d", &testNum);

    for (int q = 1; q <= testNum; q++)
    {
        printf("Case #%d\n", q);

        int matrixSize;
        scanf("%d", &matrixSize);
        int matrix[matrixSize][matrixSize];
        for (int i = 0; i < matrixSize; i++)
            for (int j = 0; j < matrixSize; j++)
                scanf("%1d", &matrix[i][j]);

        int commandCount;
        char command[10];
        int a, b;
        scanf("%d", &commandCount);
        for (int c = 0; c < commandCount; c++)
        {
            scanf("%s", command);
            if (strcmp(command, "row") == 0 || strcmp(command, "col") == 0)
                scanf("%d %d", &a, &b);

            if (strcmp(command, "row") == 0)
            {
                for (int i = 0; i < matrixSize; i++)
                    swap(&matrix[a-1][i], &matrix[b-1][i]);
            }
            else if (strcmp(command, "col") == 0)
            {
                for (int i = 0; i < matrixSize; i++)
                    swap(&matrix[i][a-1], &matrix[i][b-1]);
            }
            else if (strcmp(command, "inc") == 0)
            {
                for (int i = 0; i < matrixSize; i++)
                    for (int j = 0; j < matrixSize; j++)
                        matrix[i][j] = (matrix[i][j]+1) % 10;
            }
            else if (strcmp(command, "dec") == 0)
            {
                for (int i = 0; i < matrixSize; i++)
                    for (int j = 0; j < matrixSize; j++)
                        matrix[i][j] = (matrix[i][j]-1+10) % 10;
            }
            else if (strcmp(command, "transpose") == 0)
            {
                for (int i = 0; i < matrixSize; i++)
                    for (int j = 0; j < matrixSize; j++)
                        if (i > j)
                            swap(&matrix[i][j], &matrix[j][i]);
            }
        }

        for (int i = 0; i < matrixSize; i++)
        {
            for (int j = 0; j < matrixSize; j++)
                printf("%d", matrix[i][j]);
            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}