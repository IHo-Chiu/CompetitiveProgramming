#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define ARR_MAX_SIZE 256

int A[ARR_MAX_SIZE];
int B[ARR_MAX_SIZE];
int C[ARR_MAX_SIZE*2];
int lenA, lenB, lenC;
    
void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse(char *first, char *last) {
    --last;
    while (first < last) {
        swap(first, last);
        ++first;
        --last;
    }
}

void calc()
{
    lenC = 1;
    if (lenA == 1 && A[0] == 0)
        return;
    if (lenB == 1 && B[0] == 0)
        return;

    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            C[i+j] += A[i]*B[j];
        }
    }
    lenC = lenA + lenB;

    for (int i = 0; i < lenC; i++)
    {
        if (C[i] >= 10)
        {
            C[i+1] += C[i]/10;
            C[i] = C[i]%10;
        }
    }

    while (C[lenC-1] == 0)
    {
        lenC--;
    }
}

int main()
{

    char strA[ARR_MAX_SIZE];
    char strB[ARR_MAX_SIZE];
    while (scanf("%s %s", strA, strB) != EOF)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        lenA = strlen(strA);
        lenB = strlen(strB);
        reverse(&strA[0], &strA[lenA]);
        reverse(&strB[0], &strB[lenB]);
        for (int i = 0; i < lenA; i++)
        {
            A[i] = strA[i]-'0';
        }
        for (int i = 0; i < lenB; i++)
        {
            B[i] = strB[i]-'0';
        }

        calc();

        for (int i = lenC-1; i >= 0; i--)
        {
            putchar(C[i]+'0');
        }
        putchar('\n');
    }

    return 0;
}