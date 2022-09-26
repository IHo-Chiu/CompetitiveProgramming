# include <stdio.h>

int main()
{
    int H, U, D, F;
    double cur_pos;
    double upward, upward_decrease; 
    while (scanf("%d %d %d %d", &H, &U, &D, &F) != EOF)
    {
        if (H == 0 && U == 0 && D == 0 && F == 0)
            break;

        cur_pos = 0;
        upward = (double)U;
        upward_decrease = (double)U*F/100;
        for (int day = 1; true; day++)
        {
            cur_pos += upward;
            //printf("day %d >> cur_pos = %lf\n", day, cur_pos);
            if (cur_pos > H)
            {
                printf("success on day %d\n", day);
                break;
            }

            cur_pos -= D;
            if (cur_pos < 0)
            {
                printf("failure on day %d\n", day);
                break;
            }
            upward -= upward_decrease;
            if (upward < 0)
                upward = 0;
        }


    }

    return 0;
}