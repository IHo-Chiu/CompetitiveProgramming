/*
    Author : I-HO CHIU
    Date : 2022/4/18
    UVa : 10038 - Jolly Jumpers
    ref : https://web.ntnu.edu.tw/~algo/AlgorithmDesign.html#1
*/

#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
    int n;
    int arr[3000];
    bool isJolly;

    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
        {
            printf("Jolly\n");
            scanf("%d", arr);
            continue;
        }

        isJolly = true;
        scanf("%d", arr);
        for (int *cur = arr; cur < arr+n-1; cur++)
        {
            scanf("%d", cur+1);
            *cur = abs(*cur - *(cur+1));
        }

        std::sort(arr, arr+n-1);

        if (*arr != 1)
            isJolly = false;
        else{
            for (int *cur = arr; cur < arr+n-2; cur++)
                if (*cur+1 != *(cur+1)) {
                    isJolly = false;
                    break;
                }
        }

        if (isJolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }

    return 0;
}