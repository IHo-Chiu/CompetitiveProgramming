#include <stdio.h>
#include <memory.h>

int bigNum[100000];
int top;

void initBigNum()
{
    memset(bigNum, 0, sizeof(bigNum));
    top = 0;
    bigNum[0] = 1;
}

void printBigNum()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d", bigNum[i]);
    }
    printf("\n");
}

void mult(int n)
{
    for (int i = 0; i <= top; i++)
    {
        bigNum[i] *= n;
    }
    for (int i = 0; i < top; i++)
    {
        bigNum[i+1] += bigNum[i]/10;
        bigNum[i] %= 10;
    }
    while (bigNum[top] >= 10)
    {
        bigNum[top+1] = bigNum[top]/10;
        bigNum[top] %= 10;
        top++;
    }
}

void calcFactorial(int n)
{
    for (int i = 1; i <= n; i++)
    {
        mult(i);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d!\n", n);

        initBigNum();
        calcFactorial(n);
        printBigNum();
    }

    return 0;
}