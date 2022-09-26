#include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc getchar_unlocked
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

unsigned char scanInt()
{
    register char ch;
    register unsigned char x = 0;
    if ((ch = gc()) >= '0')
    {
        x = ch - '0';
        if ((ch = gc()) >= '0')
        {
            if (x == 2)
                x = 20;
            else
                x = ch - 38;
            gc();
        }
    }
    
    return x;
}

void printUInt(char n) {

    if (n>9)
    {
        if (n == 20)
            pc('2'), pc('0');
        else
            pc('1'), pc(n+38);
    }
    else pc(n+48);
}

int main()
{
    char ch;
    char n = scanInt();
    char seq[n];
    char LIS[n+1];
    char stack[n];
    register int top;
    register int i, j, t;

    for (i = 0; i < n; i++)
        seq[i] = scanInt();

    stack[0] = 0;
    while (1)
    {
        LIS[seq[0]] = scanInt();
        if (LIS[seq[0]] == 0)
            break;
        for (i = 1; i < n; i++)
            LIS[seq[i]] = scanInt();

        top = 0;
        for (i = 1; i <= n; i++)
        {
            t = LIS[i];
            if (stack[top] < t)
            {
                stack[++top] = t;
            }
            else
            {
                for (j = top-1; j >= 0; j--)
                {
                    if (stack[j] < t) {
                        stack[j+1] = t;
                        break;
                    }
                }
            }
        }

        printUInt(top);
        pc('\n');
    }

    return 0;
}

/*


3 1 2 4 9 5 10 6 8 7
4 7 2 3 10 6 9 1 5 8
-> (3,4), (1,7), ..., (7,8)

put 4 to index = 3
put 7 to index = 1
...
put 8 to index = 7
-> 7 2 4 3 6 1 8 5 10 9

LIS algorithm
7
2
2 4
2 3
2 3 6
1 3 6
1 3 6 8
1 3 5 8
1 3 5 8 10
1 3 5 8 9
-> LIS = 5

*/