#include <stdio.h>

int main()
{
    int x_max, y_max, x_cur, y_cur, x_test, y_test;;
    char orientation_cur;
    char inputChar = '\0';
    bool startProcess = false;
    bool abortProcess = false;

    scanf("%d %d", &x_max, &y_max);
    bool isLost[x_max+1][y_max+1];
    for (int i = 0; i <= x_max; i++)
        for (int j = 0; j <= y_max; j++)
            isLost[i][j] = false;

    while (scanf("%d %d", &x_cur, &y_cur) != EOF)
    {
        while ((inputChar = getchar()) != EOF)
        {
            if (inputChar == '\n')
            {
                startProcess = !startProcess;
                if (startProcess == false)
                {
                    printf("%d %d %c", x_cur, y_cur, orientation_cur);
                    if (abortProcess) {
                        printf(" LOST");
                        abortProcess = false;
                    }
                    printf("\n");

                    break;
                }
            }
            else if (inputChar != ' ' && abortProcess != true)
            {
                if (startProcess)
                {
                    switch (inputChar)
                    {
                        case 'R': {
                            switch (orientation_cur)
                            {
                                case 'N': orientation_cur = 'E'; break;
                                case 'E': orientation_cur = 'S'; break;
                                case 'S': orientation_cur = 'W'; break;
                                case 'W': orientation_cur = 'N'; break;
                            }
                        } break;
                        case 'L': {
                            switch (orientation_cur)
                            {
                                case 'N': orientation_cur = 'W'; break;
                                case 'E': orientation_cur = 'N'; break;
                                case 'S': orientation_cur = 'E'; break;
                                case 'W': orientation_cur = 'S'; break;
                            }
                        } break;
                        case 'F': {
                            switch (orientation_cur)
                            {
                                case 'N': x_test = x_cur, y_test = y_cur+1; break;
                                case 'E': x_test = x_cur+1, y_test = y_cur; break;
                                case 'S': x_test = x_cur, y_test = y_cur-1; break;
                                case 'W': x_test = x_cur-1, y_test = y_cur; break;
                            }

                            if (x_test > x_max || x_test < 0 || y_test > y_max || y_test < 0)
                            {
                                if (isLost[x_cur][y_cur] == false)
                                {
                                    isLost[x_cur][y_cur] = true;
                                    abortProcess = true;
                                }
                            }
                            else
                            {
                                x_cur = x_test;
                                y_cur = y_test;
                            }
                        } break;
                    }
                }
                else 
                {
                    orientation_cur = inputChar;
                }
            }
        }
    }

    return 0;
}