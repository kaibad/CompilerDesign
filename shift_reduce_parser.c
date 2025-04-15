#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[20], stack[40];
int ip_ptr = 0, st_ptr = 0, len;

void display(const char *action)
{
    printf("\n %-15s %-15s %-15s", stack, &input[ip_ptr], action);
}

void reduce()
{
    while (1)
    {
        // Look for pattern: E+E, E/E, E*E and reduce to E
        if (st_ptr >= 3 &&
            stack[st_ptr - 3] == 'E' &&
            (stack[st_ptr - 2] == '+' || stack[st_ptr - 2] == '/' || stack[st_ptr - 2] == '*') &&
            stack[st_ptr - 1] == 'E')
        {

            stack[st_ptr - 3] = 'E';
            st_ptr -= 2;
            stack[st_ptr] = '\0';
            char prod[10];
            sprintf(prod, "E->E%cE", stack[st_ptr + 1]);
            display(prod);
        }
        // Reduce 'a' or 'b' to E
        else if (st_ptr >= 1 && (stack[st_ptr - 1] == 'a' || stack[st_ptr - 1] == 'b'))
        {
            stack[st_ptr - 1] = 'E';
            char prod[10];
            sprintf(prod, "E->%c", stack[st_ptr - 1]);
            display(prod);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    printf("\n\t\tShift Reduce Parser\n");
    printf("\nGrammar:\n");
    printf(" E -> E+E\n E -> E/E\n E -> E*E\n E -> a | b\n");

    printf("\nEnter the input symbol: ");
    scanf("%s", input);
    strcat(input, "$");
    len = strlen(input);

    printf("\n%-15s %-15s %-15s", "Stack", "Input", "Action");
    printf("\n%-15s %-15s %-15s", "-----", "-----", "------");

    while (ip_ptr < len)
    {
        // Shift
        char sym = input[ip_ptr];
        stack[st_ptr++] = sym;
        stack[st_ptr] = '\0';
        ip_ptr++;

        char act[20] = "Shift ";
        strncat(act, &sym, 1);
        display(act);

        // Try to reduce
        reduce();

        if (stack[0] == 'E' && stack[1] == '\0' && input[ip_ptr] == '$')
        {
            display("Accept");
            printf("\n\nName: Kailash Badu.... Roll_no: 09\n");
            return 0;
        }
    }

    printf("\nReject\n");
    return 0;
}
