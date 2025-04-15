#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char state = 'A'; // Start state
    int i;

    printf("Enter the string over {a, b}: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
        {
            printf("Invalid character '%c' found. Only 'a' and 'b' are allowed.\n", str[i]);
            return 1;
        }

        switch (state)
        {
        case 'A':
            if (str[i] == 'a')
                state = 'B';
            // 'b' keeps it in 'A'
            break;
        case 'B':
            if (str[i] == 'a')
                state = 'A';
            // 'b' keeps it in 'B'
            break;
        }
    }

    if (state == 'B')
    {
        printf("%s Accepted.\n", str);
    }
    else
    {
        printf("%s Rejected.\n", str);
    }

    printf("\nName: Kailash Badu.... Roll_no: 09\n");

    return 0;
}
