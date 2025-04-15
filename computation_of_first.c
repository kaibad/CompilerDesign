#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char result[], char symbol);
void addToResultSet(char result[], char symbol);

int numOfProductions;
char productionSet[10][10];

int main()
{
    int i;
    char choice;
    char ch;
    char result[20];

    printf("How many number of productions?: ");
    scanf("%d", &numOfProductions);

    getchar(); // consume newline after number input

    for (i = 0; i < numOfProductions; i++)
    {
        printf("Enter production number %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do
    {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &ch);

        result[0] = '\0'; // clear previous result
        FIRST(result, ch);

        printf("FIRST(%c) = {", ch);
        for (i = 0; result[i] != '\0'; i++)
        {
            printf("%c", result[i]);
            if (result[i + 1] != '\0')
            {
                printf(", ");
            }
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nName: Kailash Badu.... Roll_no: 09\n");

    return 0;
}

void FIRST(char result[], char symbol)
{
    int i, j;
    char subResult[20];
    int hasEpsilon;

    // If symbol is terminal
    if (!isupper(symbol))
    {
        addToResultSet(result, symbol);
        return;
    }

    // Go through all productions
    for (i = 0; i < numOfProductions; i++)
    {
        if (productionSet[i][0] == symbol)
        {
            // If it's epsilon production (e.g., A->$)
            if (productionSet[i][2] == '$')
            {
                addToResultSet(result, '$');
            }
            else
            {
                j = 2;
                hasEpsilon = 0;

                do
                {
                    subResult[0] = '\0'; // clear previous result
                    FIRST(subResult, productionSet[i][j]);

                    // Add everything from subResult to result
                    for (int k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] != '$')
                        {
                            addToResultSet(result, subResult[k]);
                        }
                        else
                        {
                            hasEpsilon = 1;
                        }
                    }

                    if (hasEpsilon)
                    {
                        j++; // check next symbol in production
                    }

                } while (hasEpsilon && productionSet[i][j] != '\0');

                if (hasEpsilon && productionSet[i][j] == '\0')
                {
                    addToResultSet(result, '$');
                }
            }
        }
    }
}

void addToResultSet(char result[], char symbol)
{
    for (int i = 0; result[i] != '\0'; i++)
    {
        if (result[i] == symbol)
            return; // already added
    }
    int len = strlen(result);
    result[len] = symbol;
    result[len + 1] = '\0';
}
