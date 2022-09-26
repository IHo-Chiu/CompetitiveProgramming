#include <stdio.h>
#include <math.h>

int main(){
    unsigned int n;
    double intPart;
    while (scanf("%d", &n) && n != 0)
    {
        if (modf(sqrt(n), &intPart) == 0.0)
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0 ;
}