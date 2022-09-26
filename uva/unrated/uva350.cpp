# include <stdio.h>
# include <memory.h>
int main()
{
    int Z, I, M, L, q=0, seq;
    int hash[10000];
    while (scanf("%d %d %d %d", &Z, &I, &M, &L) != EOF)
    {
        if (!Z && !I && !M && !L)
            break;
        
        memset(hash, 0, sizeof(hash));
        for (seq = 1; hash[L] == 0; seq++)
        {
            hash[L] = seq;
            L = (Z*L+I)%M;
        }

        printf("Case %d: %d\n", ++q, seq - hash[L]);
    }

    return 0;
}