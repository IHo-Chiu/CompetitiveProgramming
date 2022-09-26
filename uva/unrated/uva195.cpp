#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <algorithm>

bool compare(char a, char b){
    char lower_a = tolower(a), lower_b = tolower(b);
    if( lower_a == lower_b ) return a < b;
    else return lower_a < lower_b; 
}

int main()
{
    int wordNum = 0;
    char str[100];
    while (scanf("%d", &wordNum) != EOF && wordNum > 0) {
        for (int i = 0; i < wordNum; i++)
        {
            scanf("%s", str);
            char *strEnd = str + strlen(str);
            std::sort(str, strEnd, compare);
            do {
                printf("%s\n", str);
            } while (std::next_permutation(str, strEnd, compare));
        }
    }


    return 0;
}