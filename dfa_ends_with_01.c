#include <stdio.h>
#include <string.h>

enum states
{
    q0,
    q1,
    qf
};

// Transition function declaration
enum states delta(enum states, char);

int main()
{
    char input[20];
    enum states curr_state = q0;
    int i = 0;

    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline if present
    input[strcspn(input, "\n")] = 0;

    // Input validation: only '0' and '1' allowed
    while (input[i] != '\0')
    {
        char ch = input[i];
        if (ch != '0' && ch != '1')
        {
            printf("\nInvalid character '%c' in input. Only binary digits (0 and 1) are allowed.\n", ch);
            return 1;
        }
        curr_state = delta(curr_state, ch);
        i++;
    }

    if (curr_state == qf)
        printf("\nThe string \"%s\" is accepted.", input);
    else
        printf("\nThe string \"%s\" is not accepted.", input);

    printf("\nName: Kailash Badu.... Roll_no: 09\n");
    return 0;
}

// State transition logic
enum states delta(enum states s, char ch)
{
    switch (s)
    {
    case q0:
        return (ch == '0') ? q1 : q0;
    case q1:
        return (ch == '1') ? qf : q1;
    case qf:
        return (ch == '0') ? q1 : q0;
    default:
        return q0; // fallback, shouldn't hit this
    }
}
