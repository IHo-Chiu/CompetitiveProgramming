#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked

int main()
{
    double x, y;
    int step;
    int direction;
    char ch;
    int q = 0;
    double sqrt_2 = sqrt(2)/2;
    bool isStart = false;
    bool isFirst = true;
    x = y = 0;
    step = 0;
    direction = 0;
    ch = 0;
    while (true)
    {
        ch = gc();
        if (ch == EOF) break;
        else if (ch == '\n')
        {
            if (isStart == false)
                break;

            x = y = 0;
            ch = 0;
            isStart = false;
        }
        else if (ch >= '0' && ch <= '9')
        {
            step = step*10 + ch - '0';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            if (direction == 0)
            {
                if (ch == 'N') direction = 1;
                else if (ch == 'E') direction = 3;
                else if (ch == 'S') direction = 5;
                else if (ch == 'W') direction = 7;
            }
            else if (direction == 1)
            {
                if (ch == 'E') direction = 2;
                else if (ch == 'W') direction = 8;
            }
            else if (direction == 5)
            {
                if (ch == 'E') direction = 4;
                else if (ch == 'W') direction = 6;
            }
        }
        else if (ch == ',' || ch == '.')
        {
            //printf(" >> direction = %d, step = %d\n", direction, step);
            isStart = true; 

            if (direction == 1) y += step;
            else if (direction == 3) x += step;
            else if (direction == 5) y -= step;
            else if (direction == 7) x -= step;
            else if (direction == 2) x += sqrt_2*step, y += sqrt_2*step;
            else if (direction == 4) x += sqrt_2*step, y -= sqrt_2*step;
            else if (direction == 6) x -= sqrt_2*step, y -= sqrt_2*step;
            else if (direction == 8) x -= sqrt_2*step, y += sqrt_2*step;

            step = direction = 0;

            if (ch == '.')
            {
                //if (isFirst) isFirst = false;
                //else printf("\n");

                printf("Map #%d\n", ++q);
                printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
                printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x + y*y));
            }
        }
    }

    return 0;
}