#include <stdio.h>
#include <math.h>

int main()
{
    int H, M;
    double H_angle, M_angle, ans;
    while (scanf("%d:%d", &H, &M) != EOF)
    {
        if (H == 0 && M == 0)
            break;

        if (H == 12)
            H = 0;
        
        H_angle = (double)H*30 + (double)M*0.5 ;
        M_angle = (double)M*6;
        
        ans = abs(H_angle-M_angle);
        if (ans > 180)
            ans = 360-ans;
        printf("%.3f\n", ans);
    }

    return 0;
}