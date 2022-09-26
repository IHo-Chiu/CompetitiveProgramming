# include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

unsigned int scanInt()
{
    register char ch;
    register unsigned int x = 0;
    while ((ch = gc()) >= '0')
        x = x * 10 + ch - '0';
    
    return x;
}

int main()
{
    int stack[1001] = {0};
    int N, input;
    register int top, currentNumber, inputCount;
    while (N = scanInt())
        while (input = scanInt())
        {
            top = 0;
            currentNumber = 0;
            inputCount = 1;
            do {
                stack[++top] = ++currentNumber;
                while (stack[top] == input)
                {
                    top--;

                    if (inputCount != N)
                    {
                        input = scanInt();
                        inputCount++;
                    }
                    else break;
                }
            } while (currentNumber != N);

            if (top)
            {
                pc('N'), pc('o'), pc('\n');
                while (gc() != '\n')
                    ;
            }
            else pc('Y'), pc('e'), pc('s'), pc('\n');
        }
}