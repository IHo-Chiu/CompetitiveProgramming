#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

#define max(a, b) (a > b ? a : b)

unsigned int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printUInt(unsigned int n) {
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

void printAnswer(int qNum, int answer)
{
    pc('T'), pc('w'), pc('i'), pc('n');
    pc(' ');
    pc('T'), pc('o'), pc('w'), pc('e'), pc('r'), pc('s');
    pc(' ');
    pc('#');
    printUInt(qNum);
    pc('\n');
    pc('N'), pc('u'), pc('m'), pc('b'), pc('e'), pc('r');
    pc(' ');
    pc('o'), pc('f');
    pc(' ');
    pc('T'), pc('i'), pc('l'), pc('e'), pc('s');
    pc(' ');
    pc(':');
    pc(' ');
    printUInt(answer);
    pc('\n');
    pc('\n');
}

int main()
{
    int n1, n2, qNum = 0;
    int arr1[101], arr2[101];
    int LCS[101][101];
    while (1)
    {
        n1 = scanInt();
        if (n1 == 0) break;
        n2 = scanInt();

        for (int i = 1; i <= n1; i++)
            arr1[i] = scanInt();
        for (int i = 1; i <= n2; i++)
            arr2[i] = scanInt();

        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (arr1[i] == arr2[j])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);

        printAnswer(++qNum, LCS[n1][n2]);
    }

    return 0;
}