#include <stdio.h>
#include <string.h>

enum states
{
    q0,
    q1,
    q2,
    qf
};

// State transition function
enum states delta(enum states, char);

int main()
{
    enum states curr_state = q0;
    char string[20];
    int i = 0;

    printf("\nEnter a binary string: ");
    fgets(string, sizeof(string), stdin);

    // Remove newline character if present
    string[strcspn(string, "\n")] = 0;

    // Process input character-by-character
    char ch = string[i];
    while (ch != '\0')
    {
        if (ch != '0' && ch != '1')
        {
            printf("\nInvalid character '%c'. Only 0 and 1 are allowed.\n", ch);
            return 1;
        }
        curr_state = delta(curr_state, ch);
        ch = string[++i];
    }

    if (curr_state == qf)
        printf("\nThe string \"%s\" is valid.", string);
    else
        printf("\nThe string \"%s\" is not valid.", string);

    printf("\nName: Kailash Badu.... Roll_no: 09\n");

    return 0;
}

enum states delta(enum states s, char ch)
{
    switch (s)
    {
    case q0:
        return (ch == '0') ? q1 : q0;

    case q1:
        return (ch == '0') ? q2 : q0;

    case q2:
        return (ch == '0') ? q2 : qf;

    case qf:
        return qf; // Stays in qf regardless of input
    }
    return q0; // Fallback to q0, should never reach here
}
