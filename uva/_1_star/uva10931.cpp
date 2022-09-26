# include <stdio.h>

int main ()
{
    int x, cnt;
    char stack[33];
    char *ch;
    while (scanf("%d", &x) && x)
    {
        for (ch = stack, cnt = 0; x > 0; x >>= 1)
        {
            if (x&1)
            {
                *ch++ = '1';
                cnt++;
            }
            else *ch++ = '0';
        }

        printf("The parity of ");
        while (ch > stack)
            putchar_unlocked(*--ch);

        printf(" is %d (mod 2).\n", cnt);
    }

    return 0;
}