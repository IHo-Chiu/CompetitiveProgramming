#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <algorithm>

int hash[128];

bool compare(int a, int b) {
    if (hash[a] == hash[b])
        return a < b;
    return hash[a] > hash[b];
}

int main()
{
    char ch;
    char out[26];
    int outSize = 0;
    memset(hash, 0, sizeof(hash));
    while ((ch = getchar_unlocked()) != EOF)
    {
        if (isalpha(ch))
            hash[toupper(ch)]++;
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (hash[i] > 0)
            out[outSize++] = i;
    }

    std::sort(out, out + outSize, compare);

    for (int i = 0; i < outSize; i++)
    {
        printf("%c %d\n", out[i], hash[out[i]]);
    }

    return 0;
}