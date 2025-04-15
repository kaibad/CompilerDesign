#include <stdio.h>
#include <string.h>

void find_prefix(char string[]);
void find_suffix(char string[]);
void find_substring(char string[], int, int);

int main() {
    char string[100];
    int i, j;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove trailing newline if exists
    string[strcspn(string, "\n")] = '\0';

    printf("\nPrefixes:\n");
    find_prefix(string);

    printf("\nSuffixes:\n");
    find_suffix(string);

    printf("\nEnter i and j for substring (1-based indexing): ");
    scanf("%d%d", &i, &j);
    find_substring(string, i, j);

    return 0;
}

void find_prefix(char string[]) {
    int i;
    char prefix[100];
    for (i = 1; i <= strlen(string); i++) {
        strncpy(prefix, string, i);
        prefix[i] = '\0';
        printf("%s\n", prefix);
    }
}

void find_suffix(char string[]) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        printf("%s\n", &string[i]);
    }
}

void find_substring(char string[], int x, int y) {
    char substr[100];
    int len = strlen(string);

    if (x < 1 || y > len || x > y) {
        printf("\nInvalid substring indices.\n");
        return;
    }

    int k = 0;
    for (int i = x - 1; i < y; i++) {
        substr[k++] = string[i];
    }
    substr[k] = '\0';

    printf("\nSubstring: %s\n", substr);
    printf("Name: Kailash Badu.... Roll_no: 09\n");
}
