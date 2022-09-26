# include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc readchar
#define pc putchar_unlocked

inline char readchar() {
    static char buf[1<<15], *p = buf, *q = buf;
    if(p == q && (q = (p=buf)+fread(buf,1,1<<15,stdin)) == buf) return EOF;
    return *p++;
}

int main()
{
    char ch;
    bool t = false;
    while ((ch = gc()) != EOF)
    {
        if (ch == '"')
        {
            t = !t;
            if (t) pc('`'), pc('`');
            else pc('\''), pc('\'');
        }
        else pc(ch);
    }

    return 0;
}