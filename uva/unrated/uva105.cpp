#include <stdio.h>
#include <stdlib.h>

# define DEBUG false

struct Node {
    int startPos;
    int high;
    Node * next;
};
Node * head;

Node * newNode(int startPos, int high, Node * next)
{
    Node * node = new Node();
    node->startPos = startPos;
    node->high = high;
    node->next = next;
    return node;
}

void printList()
{
    for (Node * cur2 = head; cur2 != NULL;  cur2 = cur2->next) {
        printf("(%d,%d)", cur2->startPos, cur2->high);
    }
    printf("\n");
}

void printAnswer()
{
    for (Node * cur2 = head; cur2 != NULL;  cur2 = cur2->next) {
        printf("%d %d", cur2->startPos, cur2->high);
        if (cur2->next == NULL)
            printf("\n");
        else
            printf(" ");
    }
}

void insert(int right, int high, int left)
{
    Node * cur = NULL;
    Node * pre = NULL;
    bool isPosEdge = false;
    int curPos = 0;
    int originalHigh = 0;
    for (cur = head; cur != NULL; pre = cur, cur = cur->next) {
        curPos = cur->startPos;
        if (curPos > left) {
            break;
        }

        if (curPos < right && cur->next != NULL && cur->next->startPos > right) {
            originalHigh = cur->high;
            if (high < cur->high) {
                cur->next = newNode(right, cur->high, cur->next);
            }
            else {
                cur->next = newNode(right, high, cur->next);
            }
            if (DEBUG) printList();

            pre = cur, cur = cur->next;
        }

        if (curPos >= right && curPos <= left) {
            originalHigh = cur->high;
            if (cur->high < high && curPos != left)
                cur->high = high;
            if (DEBUG) printList();
        }

        if (cur->next != NULL && cur->next->startPos > left) {
            cur->next = newNode(left, originalHigh, cur->next);
            if (DEBUG) printList();

            pre = cur, cur = cur->next;
        }
    }

    if (curPos < right) {
        if (pre == NULL) {
            head = newNode(right, high, newNode(left, 0, NULL));
        }
        else {
            pre->next = newNode(right, high, newNode(left, 0, NULL));
        }
    }
    else if (curPos < left) {
        pre->next = newNode(curPos, high, newNode(left, 0, NULL));
    }

    if (DEBUG) printf("post process-----\n");
    if (DEBUG) printList();
    if (DEBUG) printf("minimize-----\n");

    for (cur = head, pre = NULL; cur != NULL;) {
        curPos = cur->startPos;
        if (cur->next != NULL && cur->high == cur->next->high) {
            cur->next = cur->next->next;
            if (DEBUG) printList();
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}

int main()
{
    Node * head = NULL;
    int right, high, left;
    while (scanf("%d %d %d", &right, &high, &left) != EOF)
    {
        if (DEBUG) {
            printf("\ninsert ---------------\n");
            printf("%d %d %d\n", right, high, left);
        }
        insert(right, high, left);

        if (DEBUG) printAnswer();
    }

    printAnswer();

    return 0;
}