# include <stdio.h>
# include <memory.h>

int main()
{
    int Q = 0, N, X, people_left;
    int poker[20];
    bool people[51];
    bool down_flag;
    while (scanf("%d %d", &N, &X) != EOF)
    {
        for (int i = 0; i < 20; i++)
            scanf("%d", &poker[i]);
        
        memset(people, 1, sizeof(people));
        people_left = N;
        down_flag = (people_left <= X);
        for (int i = 0; i < 20 && !down_flag; i++)
        {
            int cnt = 0;
            for (int j = 0; j < N && !down_flag; j++)
            {
                if (people[j])
                {
                    cnt++;
                    if ((cnt%poker[i]) == 0)
                    {
                        people[j] = 0;
                        people_left--;
                        if (people_left == X)
                            down_flag = true;
                    }
                }
            }
        }

        printf("Selection #%d\n", ++Q);
        bool isFirst = true;
        for (int i = 0; i < N; i++)
            if (people[i])
            {
                if (isFirst) isFirst = false;
                else printf(" ");
                printf("%d", i+1);
            }
        printf("\n\n");
    }

    return 0;
}