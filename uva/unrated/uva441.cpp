# include <stdio.h>

int arr[13], lucky[6];
int size = 0, k;
void DFS(int idx)
{
    if (size == 6)
    {
        for (int i = 0; i < 5; i++)
            printf("%d ", lucky[i]);
        printf("%d\n", lucky[5]);
    }
    else {
        while (idx < k)
        {
            lucky[size++] = arr[idx];
            DFS(++idx);
            size--;
        }
    }
}

int main()
{
    bool isFirst = true;
    while (scanf("%d", &k) != EOF && k != 0)
    {
        for (int i = 0; i < k; i++)
            scanf("%d", &arr[i]);

        if (isFirst) isFirst = false;
        else printf("\n");
        
        DFS(0);
    }

    return 0;
}