#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char identifier[100];
    int flag = 1;

    printf("Enter an identifier: ");
    fgets(identifier, sizeof(identifier), stdin);

    // Remove trailing newline if present
    identifier[strcspn(identifier, "\n")] = '\0';

    if (!isalpha(identifier[0]) && identifier[0] != '_')
    {
        flag = 0;
    }
    else
    {
        for (int i = 1; identifier[i] != '\0'; i++)
        {
            if (!isalnum(identifier[i]) && identifier[i] != '_')
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag)
        printf("\nIt is a valid identifier");
    else
        printf("\nIt is not a valid identifier");

    printf("\nName: Kailash Badu....Roll_no: 09\n");
    return 0;
}
