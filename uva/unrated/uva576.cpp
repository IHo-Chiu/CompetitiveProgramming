#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

#define SYLLABLE_COUNT 6
char syllables[SYLLABLE_COUNT] = {'a', 'e', 'i', 'o', 'u', 'y'};
bool isSyllable(char src)
{
    for (int i = 0; i < SYLLABLE_COUNT; i++)
        if (src == syllables[i])
            return true;
    return false;
}

int main()
{
    char ch = '\0';
    int part[3], cur_part;
    bool pre_isSyllable, cur_isSyllable;
    part[0] = part[1] = part[2] = 0;
    cur_part = 0;
    pre_isSyllable = cur_isSyllable = false;
    char firstChar[3];
    firstChar[0] = firstChar[1] = firstChar[2] = 0;
    while (true)
    {
        ch = gc();
        if (ch == EOF) break;

        pre_isSyllable = cur_isSyllable;
        cur_isSyllable = isSyllable(ch);
        if (ch == '\n')
        {
            if (firstChar[0] == 'e' && firstChar[1] == 'o' && firstChar[2] == 'i')
                break;
            if (part[0] != 5) pc('1');
            else if (part[1] != 7) pc('2');
            else if (part[2] != 5) pc('3');
            else pc('Y');
            pc('\n');
            part[0] = part[1] = part[2] = 0;
            cur_part = 0;
            firstChar[0] = firstChar[1] = firstChar[2] = 0;
        }
        else if (ch == '/')
            cur_part++;
        else {
            if (firstChar[cur_part] == 0)
                firstChar[cur_part] = ch;
            else if (firstChar[cur_part] > 32)
                firstChar[cur_part] = 1;

            if (!pre_isSyllable && cur_isSyllable)
                part[cur_part]++;
        }
    }

    return 0;
}