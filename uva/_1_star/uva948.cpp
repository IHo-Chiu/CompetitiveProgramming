#include <stdio.h>

#define F_LEN 43

int main()
{
    int F[F_LEN] = {701408733,433494437,267914296,165580141,102334155,63245986,39088169,24157817,14930352,9227465,5702887,3524578,2178309,1346269,832040,514229,317811,196418,121393,75025,46368,28657,17711,10946,6765,4181,2584,1597,987,610,377,233,144,89,55,34,21,13,8,5,3,2,1};

    int q, a, i;
    bool start;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &a);
        printf("%d = ", a);
        start = false;
        for (i = 0; i < F_LEN; i++)
        {
            if (a >= F[i]) {
                putchar('1');
                a -= F[i];
                start = true;
            }
            else if (start)
                putchar('0');
        }
        printf(" (fib)\n");
    }
    

    return 0;
}