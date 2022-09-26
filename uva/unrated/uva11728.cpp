# include <stdio.h>

#define gc readchar
#define pc putchar_unlocked

#define max(a, b) (a > b ? a : b)

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}

unsigned int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printUInt(int n) {
    if (n < 0)
    {
        pc('-'), pc('1'); 
        return;
    }
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

void printAnswer(int qNum, int answer)
{
    pc('C'), pc('a'), pc('s'), pc('e');
    pc(' ');
    printUInt(qNum);
    pc(':');
    pc(' ');
    printUInt(answer);
    pc('\n');
}

int main()
{
    int n;
    int qNum = 0;
    int ans, sum, i, j;
    while (n = scanInt())
    {
        qNum++;
        if (n == 1) {
            printAnswer(qNum, 1);
            continue;
        }
        ans = -1;
        for (i = n-1; i*i > n; i--)
        {
            sum = 0;
            for (j = 1; j*j < i; j++)
                if (i%j == 0)
                    sum += j + i/j;
            
            if (j*j == i)
                sum += j;

            if (sum == n)
            {
                ans = i;
                break;
            }
        }

        printAnswer(qNum, ans);
    }
    return 0;
}