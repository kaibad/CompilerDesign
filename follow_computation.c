#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10
#define SIZE 100

char productions[MAX][SIZE];
char firstSet[MAX][SIZE];
char followSet[MAX][SIZE];
int numProductions;

void computeFirst(char result[], char symbol);
void computeFollow(char result[], char symbol);
void addUnique(char result[], char ch);
void merge(char dest[], const char src[]);

int isNonTerminal(char ch)
{
    return isupper(ch);
}

int alreadyAdded(const char result[], char ch)
{
    for (int i = 0; result[i]; i++)
    {
        if (result[i] == ch)
            return 1;
    }
    return 0;
}

void addUnique(char result[], char ch)
{
    if (!alreadyAdded(result, ch))
    {
        int len = strlen(result);
        result[len] = ch;
        result[len + 1] = '\0';
    }
}

void merge(char dest[], const char src[])
{
    for (int i = 0; src[i]; i++)
    {
        addUnique(dest, src[i]);
    }
}

void computeFirst(char result[], char symbol)
{
    result[0] = '\0';

    if (!isNonTerminal(symbol))
    {
        addUnique(result, symbol);
        return;
    }

    for (int i = 0; i < numProductions; i++)
    {
        if (productions[i][0] == symbol)
        {
            if (productions[i][2] == '#')
            {
                addUnique(result, '#');
            }
            else
            {
                int j = 2;
                while (productions[i][j])
                {
                    char temp[SIZE] = "";
                    computeFirst(temp, productions[i][j]);
                    merge(result, temp);

                    if (!strchr(temp, '#'))
                        break;
                    j++;
                }
            }
        }
    }
}

void computeFollow(char result[], char symbol)
{
    result[0] = '\0';
    if (productions[0][0] == symbol)
        addUnique(result, '$');

    for (int i = 0; i < numProductions; i++)
    {
        int len = strlen(productions[i]);
        for (int j = 2; j < len; j++)
        {
            if (productions[i][j] == symbol)
            {
                if (j + 1 < len)
                {
                    char temp[SIZE] = "";
                    computeFirst(temp, productions[i][j + 1]);
                    for (int k = 0; temp[k]; k++)
                    {
                        if (temp[k] != '#')
                            addUnique(result, temp[k]);
                    }
                    if (strchr(temp, '#'))
                    {
                        char tempFollow[SIZE] = "";
                        computeFollow(tempFollow, productions[i][0]);
                        merge(result, tempFollow);
                    }
                }
                else if (productions[i][0] != symbol)
                {
                    char tempFollow[SIZE] = "";
                    computeFollow(tempFollow, productions[i][0]);
                    merge(result, tempFollow);
                }
            }
        }
    }
}

int main()
{
    printf("Enter number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // clear newline

    printf("Enter productions (e.g., E=TQ):\n");
    for (int i = 0; i < numProductions; i++)
    {
        scanf("%s", productions[i]);
    }

    char doneFirst[MAX] = "", doneFollow[MAX] = "";

    printf("\n-- FIRST Sets --\n");
    for (int i = 0; i < numProductions; i++)
    {
        char nonTerminal = productions[i][0];
        if (!alreadyAdded(doneFirst, nonTerminal))
        {
            char result[SIZE] = "";
            computeFirst(result, nonTerminal);
            printf("FIRST(%c) = { ", nonTerminal);
            for (int j = 0; result[j]; j++)
            {
                printf("%c", result[j]);
                if (result[j + 1])
                    printf(", ");
            }
            printf(" }\n");
            addUnique(doneFirst, nonTerminal);
        }
    }

    printf("\n-- FOLLOW Sets --\n");
    for (int i = 0; i < numProductions; i++)
    {
        char nonTerminal = productions[i][0];
        if (!alreadyAdded(doneFollow, nonTerminal))
        {
            char result[SIZE] = "";
            computeFollow(result, nonTerminal);
            printf("FOLLOW(%c) = { ", nonTerminal);
            for (int j = 0; result[j]; j++)
            {
                printf("%c", result[j]);
                if (result[j + 1])
                    printf(", ");
            }
            printf(" }\n");
            addUnique(doneFollow, nonTerminal);
        }
    }

    printf("\nName: Kailash Badu....Roll_no: 09\n");
    return 0;
}
