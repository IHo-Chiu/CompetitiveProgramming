#include <stdio.h>
#include <math.h>

int main()
{
    int n, complete_count, half_count;
    double radius, x, x_before;
    bool isFirst = true;
    while (scanf("%d", &n) != EOF)
    {
        complete_count = half_count = 0;
        x = radius = (double)n - 0.5;

        for (int y = 1; y < n; y++)
        {
            x_before = x;
            x = sqrt(radius*radius - y*y);
            complete_count += (int)x;
            half_count += (int)x_before - (int)x + 1;
            if (x_before == (int)x_before)
                half_count--;
        }
        half_count += (int)x + 1;

        if (isFirst) isFirst = false;
        else printf("\n");
        printf("In the case n = %d, %d cells contain segments of the circle.\n", n, half_count*4);
        printf("There are %d cells completely contained in the circle.\n", complete_count*4);
    }


    return 0;
}