#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 75

struct Node
{
    char *str;
    int count;
    Node *next;
};

Node *newNode(char *str, int count, Node *next)
{
    Node *node = new Node();
    node->str = str;
    node->count = count;
    node->next = next;
    return node;
}

Node *root;

void insert(char *str)
{
    if (root == NULL)
    {
        root = newNode(str, 1, NULL);
        return;
    }
    if (strcmp(str, root->str) < 0)
    {
        root = newNode(str, 1, root);
        return;
    }

    int cmp, cmp2;
    for (Node *cur = root; cur != NULL; cur = cur->next)
    {
        cmp = strcmp(str, cur->str);
        if (cmp == 0)
        {
            cur->count++;
            return;
        }

        cmp2 = cur->next == NULL ? -1 : strcmp(str, cur->next->str);
        if (cmp > 0 && cmp2 < 0)
        {
            cur->next = newNode(str, 1, cur->next);
            return;
        }
    }
}

void printList()
{
    for (Node *cur = root; cur != NULL; cur = cur->next)
    {
        printf("%s %d\n", cur->str, cur->count);
    }
}

char *scanStr()
{
    char *str = (char*) malloc(sizeof(char) * MAX_STR_LEN);
    char *cur = str;
    char ch;
    while ((ch = getchar()) != ' ')
        *cur++ = ch;
    *cur = '\0';

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return str;
}

int main()
{
    root = NULL;
    int q;
    scanf("%d", &q);
    while (getchar() != '\n')
        ;
    while (q--)
    {
        insert(scanStr());
    }

    printList();
    return 0;
}