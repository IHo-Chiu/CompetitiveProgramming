# include <stdio.h>
# include <string.h>

# define MAX_STR_LENGTH 1000

int main()
{
    char str1[MAX_STR_LENGTH];
    char str2[MAX_STR_LENGTH];
    unsigned char str1_len, str2_len;
    unsigned char LCS_table[MAX_STR_LENGTH+1][MAX_STR_LENGTH+1];

    while (fgets(str1, sizeof(str1), stdin))
    {
        fgets(str2, sizeof(str2), stdin);
        str1_len = strlen(str1);
        str2_len = strlen(str2);
        str1[--str1_len] = '\0';
        str2[--str2_len] = '\0';

        for (unsigned char i = 1; i <= str1_len; i++)
            for (unsigned char  j = 1; j <= str2_len; j++)
            {
                if (str1[i-1] == str2[j-1])
                    LCS_table[i][j] = LCS_table[i-1][j-1] + 1;
                else if (LCS_table[i-1][j] > LCS_table[i][j-1])
                    LCS_table[i][j] = LCS_table[i-1][j];
                else
                    LCS_table[i][j] = LCS_table[i][j-1];
            }

        printf("%d\n", LCS_table[str1_len][str2_len]);
    }

    return 0;
}