#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADDR_MAX_LEN 101

struct StrNode
{
    char addr[ADDR_MAX_LEN];
    StrNode *next;
};

int main()
{
    char addr[ADDR_MAX_LEN];
    int qNum, weight, max_weight;
    StrNode *head, *tail;

    scanf("%d", &qNum);
    for (int q = 1; q <= qNum; q++)
    {
        max_weight = 0;

        for (int t = 0; t < 10; t++)
        {
            scanf("%s %d", addr, &weight);
            if (weight > max_weight)
            {
                max_weight = weight;
                head = new StrNode();
                tail = head;
                strcpy(tail->addr, addr);
                tail->next = NULL;
            }
            else if (weight == max_weight)
            {
                tail->next = new StrNode();
                tail = tail->next;
                strcpy(tail->addr, addr);
                tail->next = NULL;
            }
        }

        printf("Case #%d:\n", q);
        for (StrNode *cur = head; cur != NULL; cur = cur->next)
        {
            printf("%s\n", cur->addr);
        }
    }

    return 0;
}