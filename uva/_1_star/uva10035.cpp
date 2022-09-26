#include <stdio.h>
#include <string.h>

int main()
{
    long int num1, num2;
    int cnt, carry;
    while (scanf("%ld %ld", &num1, &num2) != EOF)
    {
        if (num1 == 0 && num2 == 0)
            break;

        cnt = carry = 0;
        while (num1 > 0 || num2 > 0)
        {
            carry = (num1%10 + num2%10 + carry) / 10;
            if (carry) cnt++;
            num1 /= 10;
            num2 /= 10;
        }

        if (cnt == 0)
            printf("No carry operation.\n");
        else if (cnt == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", cnt);
    }

    return 0;
}