#include <stdio.h>
#include <string.h>

int main()
{
    char comment[100];
    int i = 2, isComment = 0;

    printf("Enter a comment: ");
    fgets(comment, sizeof(comment), stdin);

    // Remove newline character if present
    comment[strcspn(comment, "\n")] = '\0';

    if (comment[0] == '/')
    {
        if (comment[1] == '/')
        {
            printf("\nIt is a single-line comment.");
            isComment = 1;
        }
        else if (comment[1] == '*')
        {
            // Check for closing */
            while (comment[i] != '\0')
            {
                if (comment[i] == '*' && comment[i + 1] == '/')
                {
                    printf("\nIt is a multi-line comment.");
                    isComment = 1;
                    break;
                }
                i++;
            }
            if (!isComment)
                printf("\nIt is not a properly closed multi-line comment.");
        }
        else
        {
            printf("\nIt is not a comment.");
        }
    }
    else
    {
        printf("\nIt is not a comment.");
    }

    printf("\nName: Kailash Badu.... Roll_no: 09\n");
    return 0;
}
