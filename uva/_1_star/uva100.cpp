# include<stdio.h>

#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

#define gc readchar
#define pc putchar_unlocked

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
    if (n/10) printUInt(n/10);
    putchar_unlocked((n%10) + '0');
}

#define TABLE_SIZE 1000000
int table[TABLE_SIZE<<1];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

void make_table()
{
    table[TABLE_SIZE] = 1;
    for (int i = 2; i <= TABLE_SIZE; i++)
    {
        int cnt = 1;
        long long int x = i;
        while (x > 1)
        {
            cnt++;
            if (x & 1)
                x += (x << 1) + 1 ;
            else {
                x >>= 1;
                if (x < i)
                {
                    cnt += table[TABLE_SIZE+x-1] -1;
                    break;
                }
            }
        }
        table[TABLE_SIZE+i-1] = cnt;
    }

    for (int i = TABLE_SIZE-1; i > 0; i--)
        table[i] = max(table[i<<1],table[(i<<1)|1]);   
}

int calculate(int l, int r)
{
    int ans = 0;
    for (l += TABLE_SIZE, r += TABLE_SIZE; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) ans = max(ans, table[l++]);
        if (r&1) ans = max(ans, table[--r]);
    }

    return ans;
}

int main()
{
    make_table();

    int a,b,t;
    while (a = scanInt())
    {
        b = scanInt();
        printUInt(a);
        pc(' ');
        printUInt(b);
        pc(' ');
        if (b < a) swap(a,b,t);
        printUInt(calculate(a-1, b));
        pc('\n');
    }

    return 0;
}