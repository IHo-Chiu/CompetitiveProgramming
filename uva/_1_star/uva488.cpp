/*
    Author : I-Ho CHIU
    Date : 2022/4/17
    UVa : 488 - Triangle Wave
    ref : https://web.ntnu.edu.tw/~algo/AlgorithmDesign.html#1
*/

#include <stdio.h>

int main()
{
    int n, a, f;
    scanf("%d", &n);

    while (scanf("%d %d", &a, &f) != EOF)
    {
        for (int i = 0; i < f; i++)
        {
            if (i) putchar('\n');

            for (int j = 1; j <= a; j++)
            {
                for (int k = 0; k < j; k++)
                    putchar(j+'0');
                putchar('\n');
            }
            for (int j = a-1; j >= 1; j--)
            {
                for (int k = 0; k < j; k++)
                    putchar(j+'0');
                putchar('\n');
            }
        }
    }

    return 0;
}