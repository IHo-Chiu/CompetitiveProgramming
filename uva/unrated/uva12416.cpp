#include <stdio.h>

int main()
{
    char ch;
    bool isSpaceBefore = false;
    int continuousSpaceCount = 0;
    int maxContinuousSpaceCount = 0;
    while ((ch = getchar_unlocked()) != EOF)
    {
        if (ch == '\n')
        {
            int cnt = 0;
            for (maxContinuousSpaceCount--; maxContinuousSpaceCount > 0; maxContinuousSpaceCount >>= 1)
                cnt++;
            printf("%d\n", cnt);
            isSpaceBefore = false;
            continuousSpaceCount = 0;
            maxContinuousSpaceCount = 0;
        }
        else 
        {
            if (ch == ' ')
            {
                if (isSpaceBefore == false)
                {
                    isSpaceBefore = true;
                    continuousSpaceCount = 0;
                }
                continuousSpaceCount++; 
                if (maxContinuousSpaceCount < continuousSpaceCount)
                    maxContinuousSpaceCount = continuousSpaceCount;
            }
            else
            {
                isSpaceBefore = false;

            }
            
        }
    }
    
    return 0;
}