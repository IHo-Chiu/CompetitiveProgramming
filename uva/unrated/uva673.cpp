#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

#define MAX_STACK_SIZE 128

int main()
{
    int q;
    scanf("%d", &q);
    while (gc() != '\n')
        ;

    char ch = '\0';
    char stack[MAX_STACK_SIZE];
    int top;
    bool success;
    while (q--)
    {
        top = -1;
        success = true;
        while ((ch = gc()) != '\n' && ch != EOF)
        {
            if (ch == ')')
            {
                if (top == -1) success = false;
                else if (stack[top] == '(') top--;
                else success = false;
            }
            else if (ch == ']')
            {
                if (top == -1) success = false;
                else if (stack[top] == '[') top--;
                else success = false;
            }
            else stack[++top] = ch;

            if (success == false)
                break;
        }

        if (success && top == -1)
            printf("Yes\n");
        else {
            while (ch != '\n' && ch != EOF)
                ch = gc();
            printf("No\n");
        }

    }

    return 0;
}