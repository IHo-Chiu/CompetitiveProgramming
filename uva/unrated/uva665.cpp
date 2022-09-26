#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<15], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
	return *p++;
}

long scanInt()
{
    register char ch = '\0';
    register long x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

void printInt(int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

int main()
{
    int q = scanInt();

    while (q--)
    {
        gc();
        int N = scanInt();
        int K = scanInt();

        int coin[N+1];
        memset(coin, 0, sizeof(coin));

        int weightingCount;
        int left[N/2+1], right[N/2+1];
        char compareResult;

        for (int i = 0; i < K; i++)
        {
            weightingCount = scanInt();

            for (int j = 0; j < weightingCount; j++)
                left[j] = scanInt();
            for (int j = 0; j < weightingCount; j++)
                right[j] = scanInt();

            compareResult = gc();
            gc();

            if (compareResult == '=')
            {
                for (int j = 0; j < weightingCount; j++)
                    coin[left[j]] = coin[right[j]] = 1;
            }
            else if (compareResult == '<')
            {
                for (int j = 0; j < weightingCount; j++)
                {
                    if (coin[left[j]] == 0)
                        coin[left[j]] = 2;
                    else if (coin[left[j]] == 3)
                        coin[left[j]] = 1;
                    if (coin[right[j]] == 0)
                        coin[right[j]] = 3;
                    else if (coin[right[j]] == 2)
                        coin[right[j]] = 1;
                }

                for (int j = 1; j <= N; j++)
                {
                    bool isEven = true;
                    for (int k = 0; k < weightingCount; k++)
                        if (j == left[k] || j == right[k])
                        {
                            isEven = false;
                            break;
                        }
                    if (isEven)
                        coin[j] = 1;
                }
            }
            else if (compareResult == '>')
            {
                for (int j = 0; j < weightingCount; j++)
                {
                    if (coin[left[j]] == 0)
                        coin[left[j]] = 3;
                    else if (coin[left[j]] == 2)
                        coin[left[j]] = 1;
                    if (coin[right[j]] == 0)
                        coin[right[j]] = 2;
                    else if (coin[right[j]] == 3)
                        coin[right[j]] = 1;
                }

                for (int j = 1; j <= N; j++)
                {
                    bool isEven = true;
                    for (int k = 0; k < weightingCount; k++)
                        if (j == left[k] || j == right[k])
                        {
                            isEven = false;
                            break;
                        }
                    if (isEven)
                        coin[j] = 1;
                }
            }
        }

        int cnt = 0, last = 0;
        for (int i = 1; i <= N; i++)
            if (coin[i] != 1)
            {
                cnt++;
                last = i;
            }

        if (cnt == 1)
            printInt(last);
        else
            pc('0');
        
        pc('\n');
        if (q) pc('\n');
    }

    return 0;
}