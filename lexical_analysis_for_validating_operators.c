#include <stdio.h>
#include <string.h>

int main()
{
    char str[3]; // 2-character input + null terminator
    int valid = 0;

    printf("Enter operator to be identified: ");
    scanf("%2s", str); // limit input to 2 characters for safety

    // Logical Operators
    if ((str[0] == '&' && str[1] == '&') ||
        (str[0] == '|' && str[1] == '|') ||
        (str[0] == '!' && str[1] == '\0'))
    {
        printf("\nIt is a Logical operator");
        valid = 1;
    }

    // Relational Operators
    else if ((str[0] == '<' || str[0] == '>' || str[0] == '!' || str[0] == '=') &&
             (str[1] == '=' || str[1] == '\0'))
    {
        printf("\nIt is a Relational operator");
        valid = 1;
    }

    // Bitwise Operators
    else if ((str[0] == '&' || str[0] == '|' || str[0] == '^' || str[0] == '~') && str[1] == '\0')
    {
        printf("\nIt is a Bitwise operator");
        valid = 1;
    }
    else if (((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>')))
    {
        printf("\nIt is a Bitwise Shift operator");
        valid = 1;
    }

    // Ternary Operator
    else if (str[0] == '?' && str[1] == ':')
    {
        printf("\nIt is a Ternary operator");
        valid = 1;
    }

    // Unary Operators
    else if ((str[0] == '+' && str[1] == '+') || (str[0] == '-' && str[1] == '-'))
    {
        printf("\nIt is a Unary operator");
        valid = 1;
    }

    // Assignment Operators
    else if ((strchr("+-*/%", str[0]) && str[1] == '=') || (str[0] == '=' && str[1] == '='))
    {
        printf("\nIt is an Assignment operator");
        valid = 1;
    }

    // Arithmetic Operators
    else if (strchr("+-*/%", str[0]) && str[1] == '\0')
    {
        printf("\nIt is an Arithmetic operator");
        valid = 1;
    }

    // Not a valid operator
    if (!valid)
    {
        printf("\nThe input is not a valid operator");
    }

    printf("\nName: Kailash Badu....Roll_no: 09\n");
    return 0;
}
