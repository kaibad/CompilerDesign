#include <stdio.h>
#include <string.h>

char keyword[32][10] = {
    "auto", "double", "int", "struct", "break", "else", "long", "switch", "case",
    "extern", "return", "union", "const", "enum", "register", "typedef", "char",
    "float", "short", "unsigned", "continue", "for", "signed", "void", "default",
    "sizeof", "volatile", "do", "if", "static", "while"};

enum states
{
    q0, // Initial state
    qf, // Final state (valid identifier)
    qd  // Dead state (invalid identifier)
};

// Transition function declaration
enum states delta(enum states s, char ch);

// Function to check if a string is a keyword
int iskeyword(char str[]);

int main()
{
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    printf("\nEnter a string: ");
    // Use fgets instead of gets to prevent buffer overflow
    fgets(string, sizeof(string), stdin);

    // Remove newline character from fgets input if present
    string[strcspn(string, "\n")] = 0;

    if (iskeyword(string))
    {
        printf("\nThe string \"%s\" is a keyword.\n", string);
    }
    else
    {
        ch = string[i];
        while (ch != '\0')
        {
            curr_state = delta(curr_state, ch);
            ch = string[++i];
        }

        if (curr_state == qf)
        {
            printf("\nThe string \"%s\" is a valid identifier.\n", string);
        }
        else
        {
            printf("\nThe string \"%s\" is neither a keyword nor a valid identifier.\n", string);
        }
    }

    printf("\nName: Kailash Badu.... Roll_no: 09\n");
    return 0;
}

// Transition function implementation
enum states delta(enum states s, char ch)
{
    enum states curr_state;
    switch (s)
    {
    case q0:
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '_'))
        {
            curr_state = qf; // valid starting character for identifier
        }
        else
        {
            curr_state = qd; // invalid character
        }
        break;
    case qf:
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '_') || (ch >= '0' && ch <= '9'))
        {
            curr_state = qf; // valid continuation of identifier
        }
        else
        {
            curr_state = qd; // invalid character
        }
        break;
    case qd:
        curr_state = qd; // once in the dead state, stay there
        break;
    }
    return curr_state;
}

// Function to check if the string is a keyword
int iskeyword(char str[])
{
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, keyword[i]) == 0)
        {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}
