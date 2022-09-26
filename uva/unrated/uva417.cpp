#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVaild(char *str)
{
    for (int i = 1; i < strlen(str); i++)
        if (str[i-1] >= str[i])
            return false;
    return true;
}

int main()
{
    int C[27][27] = {1};
    for( int i = 1 ; i <= 26 ; ++i ){
        C[i][0] = C[i][i] = 1;
        for( int j = 1 ; j < i ; ++j )
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    char arr[5];
    while (scanf("%s", arr) != EOF)
    {
        if (isVaild(arr) == false)
        {
            printf("0\n");
            continue;
        }

        int len = strlen(arr);
        int index = 0;
        for( int i = 0 ; i < len ; ++i )
        {
            index += C[26][i];
            for( char c = ((i == 0)? 'a' : arr[i-1]+1) ; c < arr[i] ; ++c )
                index += C['z'-c][len-i-1];
        }

        printf("%d\n", index);
    }

    return 0;
}