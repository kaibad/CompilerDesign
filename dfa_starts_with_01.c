#include <stdio.h>
#include <string.h>

enum states
{
    q0, // Initial state
    q1, // Intermediate state
    qf, // Accepting state
    qd  // Dead state (invalid state)
};

// Transition function declaration
enum states delta(enum states, char);

int main()
{
    char input[20];
    enum states curr_state = q0;
    int i = 0;
    printf("\nEnter a binary string: ");

    // Use fgets to safely read the input
    fgets(input, sizeof(input), stdin);

    // Remove the newline character that fgets might add
    input[strcspn(input, "\n")] = 0;

    // Process each character in the input string
    char ch = input[i];
    while (ch != '\0')
    {
        // Check for invalid characters (must be binary)
        if (ch != '0' && ch != '1')
        {
            printf("\nThe string contains invalid characters. Only binary digits (0 or 1) are allowed.\n");
            return 0;
        }
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    // Accept or reject the input based on the final state
    if (curr_state == qf)
    {
        printf("\nThe string \"%s\" is accepted.\n", input);
    }
    else
    {
        printf("\nThe string \"%s\" is not accepted.\n", input);
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
        if (ch == '0')
        {
            curr_state = q1;
        }
        else
        {
            curr_state = qd; // Invalid state on '1' from q0
        }
        break;
    case q1:
        if (ch == '1')
        {
            curr_state = qf; // Transition to accepting state
        }
        else
        {
            curr_state = qd; // Invalid state on '0' from q1
        }
        break;
    case qf:
        // Once in the final state, remain there if '0' or '1'
        curr_state = qf;
        break;
    case qd:
        // Once in the dead state, stay there (invalid string)
        curr_state = qd;
        break;
    }
    return curr_state;
}
