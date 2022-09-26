#include <stdio.h>

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

void printUInt(unsigned int n) {
    if (n != 0)
    {
        printUInt(n/10);
        putchar_unlocked((n%10) + '0');
    }
}

int GCD(int x, int y, int limit)
{
    do {
        if (x <= limit || y <= limit)
            return 0;
    } while ((x %= y) && (y %= x));

    return x + y;
}

int main()
{
    int qNum;
    scanf("%d", &qNum);
    char ch = '\0';
    int arr[100];

    while (readchar() != '\n')
        ;

    do {
        int arrSize = 0;
        int max_gcd = 1;
        int num = 0;
        do {
            if ((ch = readchar()) >= '0')
                num = num * 10 + ch - '0';
            else if (num > 0)
            {
                arr[arrSize++] = num;
                num = 0;
            }
        } while (ch != '\n');

        for (int i = 0; i < arrSize; i++)
            for (int j = i+1; j < arrSize; j++)
            {
                int gcd = GCD(arr[i], arr[j], max_gcd);
                if (gcd > max_gcd)
                    max_gcd = gcd;
            }

        printUInt(max_gcd);
        putchar_unlocked('\n');
        
    } while (--qNum);

    return 0;
}