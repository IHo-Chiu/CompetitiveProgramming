# include <stdio.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#define gc getchar_unlocked
#define pc putchar_unlocked

#define GET_BIT(num, mask) ((num & mask) ? '1' : '0' )

inline void printBinaryNumber(short x)
{
    pc('0');
    pc(GET_BIT(x,0x800));
    pc(GET_BIT(x,0x400));
    pc(GET_BIT(x,0x200));
    pc(GET_BIT(x,0x100));
    pc(GET_BIT(x,0x080));
    pc(GET_BIT(x,0x040));
    pc(GET_BIT(x,0x020));
    pc(GET_BIT(x,0x010));
    pc(GET_BIT(x,0x008));
    pc(GET_BIT(x,0x004));
    pc(GET_BIT(x,0x002));
    pc(GET_BIT(x,0x001));
}

inline void printOperator(char op)
{
    pc(' '); 
    pc(op); 
    pc(' ');
}

int main()
{
    while (gc() != '\n') // clear first line
        ;

    char op;
    short num1, num2;
    while (scanf("%hx %c %hx", &num1, &op, &num2) != EOF)
    {
        printBinaryNumber(num1);
        printOperator(op);
        printBinaryNumber(num2);
        printOperator('=');
        printf("%d\n", (op == '+') ? num1 + num2 : num1 - num2);
    }

    return 0;
}