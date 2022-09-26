#include <stdio.h>
#include <stdbool.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
	static char buf[1<<20], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,1<<20,stdin)) == buf) return EOF;
	return *p++;
}
void printUInt(unsigned int n) {
    if (n/10) printUInt(n/10);
    pc((n%10) + '0');
}

int main()
{
    char ch;
    while ((ch = readchar()) != '~')
    {
        unsigned int ans = 0;
        bool flag = false;

        do {
            char cnt = 1;
            while ((ch = readchar()) != ' ')
                cnt++;

            if (cnt > 2) {
                cnt -= 2;
                if (flag)
                {
                    ans++;
                    ans <<= cnt;
                    ans--;
                }
                else ans <<= cnt;
            }
            else flag = cnt == 1;

        } while ((ch = readchar()) != '#');

        printUInt(ans);
        pc(readchar());
    }

    return 0;
}