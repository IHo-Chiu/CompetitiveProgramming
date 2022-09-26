#include <stdio.h>
#include <memory.h>
#include <algorithm>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
    static char buf[1<<15], *p = buf, *q = buf;
    if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
    return *p++;
}

void printInt(unsigned int n) {
    if (n/10) printInt(n/10);
    pc((n%10) + '0');
}

short hashMap[256];
bool cmp(int x, int y)
{
    return (hashMap[x] == hashMap[y]) ? x > y : hashMap[x] < hashMap[y];
}

int main()
{
    char ch, size = 0;
    char arr[128];
    bool isFirst = true;
    memset(hashMap, 0, sizeof(hashMap));
    while (true)
    {
        ch = gc();
        if (ch == '\n' || ch == EOF)
        {
            for (int i = 32; i < 127; i++)
                if (hashMap[i] > 0)
                    arr[size++] = i;
            
            std::sort(arr, arr+size, cmp);

            if (isFirst) isFirst = false;
            else pc('\n');
            for (int i = 0; i < size; i++)
            {
                printInt(arr[i]);
                pc(' ');
                printInt(hashMap[arr[i]]);
                pc('\n');
            }
            if (ch == EOF)
                break;
            size = 0;
            memset(hashMap, 0, sizeof(hashMap));

        }
        else hashMap[ch]++;
    }

    return 0;
}