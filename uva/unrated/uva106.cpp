#include <stdio.h>
#include <stdlib.h>

# define DEBUG false

struct Node {
    // c>b>a, a^2+b^2=c^2
    int a;
    int b;
    int c;
    Node * next;
};
Node * head;

Node * newNode(int a, int b, int c, Node * next)
{
    Node * node = new Node();
    node->a = a;
    node->b = b;
    node->c = c;
    node->next = next;
    return node;
}

void insert(Node *node)
{
    if (head == NULL)
    {
        head = node;
    }
    else {
        node->next = head->next;
        head->next = node;
    }
}

int gcd(int a,int b)
{
    if (b == 0) return a;
    else return gcd(b,a%b);
}

void findPythagoreanTriple(int num)
{
    int m = 0;
    int n = 1;
    int a,b,c;

    while (true)
    {
        m += 2;
        c = m*m + n*n;

        if (c > num) // next round
        {
            n++;
            m = n+1;
            c = m*m + n*n;

            if (c > num) // out of range
            {
                break;
            }
        }

        if (gcd(m,n) == 1) // Pythagorean Triple
        {
            a = m*m - n*n;
            b = 2*m*n;
            // c = m*m + n*n;  // is calculated

            insert(newNode(a,b,c,NULL));

            if(DEBUG)
            {
                printf("(%d,%d)(%d,%d,%d)\n", m,n,a,b,c);
            }
        }
    }
}

void printAnswer(int num)
{
    int primeTripleCount = 0;
    int checkedNumberCount = 0;
    bool checkList[num+1];
    for (int i = 0; i <= num; i++)
        checkList[i] = false;

    for (Node *cur = head; cur != NULL; cur = cur->next)
    {
        if(DEBUG)
        {
            printf("(%d,%d,%d)\n", cur->a, cur->b, cur->c);
        }

        primeTripleCount++;

        for (int i = 1; cur->c * i <= num; i++ )
        {
            if (checkList[cur->a * i] == false)
                checkedNumberCount++;
            if (checkList[cur->b * i] == false)
                checkedNumberCount++;
            if (checkList[cur->c * i] == false)
                checkedNumberCount++;

            checkList[cur->a * i] = true;
            checkList[cur->b * i] = true;
            checkList[cur->c * i] = true;
        }
    }

    printf("%d %d\n", primeTripleCount, num - checkedNumberCount);
}

int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        head = NULL;

        if (DEBUG) {
            printf("\nnew number ---------------\n");
            printf("%d\n", num);
        }

        findPythagoreanTriple(num);
        printAnswer(num);
    }

    return 0;
}