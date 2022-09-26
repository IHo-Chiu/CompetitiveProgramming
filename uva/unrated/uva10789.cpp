#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <math.h>

bool isPrime(int num)
{
    if (num == 0 || num == 1) return false;
    if (num == 2) return true;
    if (num%2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i+=2)
        if (num%i == 0)
            return false;
    return true; 
}

int main()
{
    int q;
    scanf("%d", &q);

    int hash[128];
    char str[2001];
    bool hasAnswer;
    for (int qq = 1; qq <= q; qq++)
    {
        memset(hash, 0, sizeof(hash));
        hasAnswer = false;

        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++)
            hash[str[i]]++;

        printf("Case %d: ", qq);
        for (int i = 32; i < 128; i++)
            if (isPrime(hash[i]))
            {
                printf("%c", (char)i);
                hasAnswer = true;
            }

        if (hasAnswer == false)
            printf("empty");

        printf("\n");
    }

    return 0;
}