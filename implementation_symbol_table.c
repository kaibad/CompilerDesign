#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null 0

struct symbtab
{
    char label[10];
    int addr;
    struct symbtab *next;
};

struct symbtab *first = NULL, *last = NULL;
int size = 0;

void insert();
void del();
int search(const char label[]);
void modify();
void display();

int main()
{
    int op;
    char label[10];

    do
    {
        printf("\nSymbol Table Implementation\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Modify\n");
        printf("6. End\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            insert();
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            del();
            display();
            break;
        case 4:
            printf("Enter the label to be searched: ");
            scanf("%s", label);
            if (search(label))
                printf("The label is already in the symbol table.\n");
            else
                printf("The label is not found in the symbol table.\n");
            break;
        case 5:
            modify();
            display();
            break;
        case 6:
            printf("\nName: Kailash Badu....Roll_no:09\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (op != 6);

    return 0;
}

void insert()
{
    char label[10];
    printf("Enter the label: ");
    scanf("%s", label);

    if (search(label))
    {
        printf("The label already exists. Duplicate can't be inserted.\n");
        return;
    }

    struct symbtab *node = (struct symbtab *)malloc(sizeof(struct symbtab));
    strcpy(node->label, label);
    printf("Enter the address: ");
    scanf("%d", &node->addr);
    node->next = NULL;

    if (first == NULL)
    {
        first = last = node;
    }
    else
    {
        last->next = node;
        last = node;
    }
    size++;
}

void display()
{
    struct symbtab *ptr = first;
    printf("Label\tAddress\n");
    while (ptr != NULL)
    {
        printf("%s\t%d\n", ptr->label, ptr->addr);
        ptr = ptr->next;
    }
}

int search(const char label[])
{
    struct symbtab *ptr = first;
    while (ptr != NULL)
    {
        if (strcmp(ptr->label, label) == 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

void modify()
{
    char oldLabel[10], newLabel[10];
    int newAddr, choice;
    struct symbtab *ptr = first;

    printf("What do you want to modify?\n");
    printf("1. Only the label\n");
    printf("2. Only the address\n");
    printf("3. Both label and address\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the label to modify: ");
    scanf("%s", oldLabel);

    while (ptr != NULL)
    {
        if (strcmp(ptr->label, oldLabel) == 0)
        {
            switch (choice)
            {
            case 1:
                printf("Enter the new label: ");
                scanf("%s", newLabel);
                strcpy(ptr->label, newLabel);
                break;
            case 2:
                printf("Enter the new address: ");
                scanf("%d", &newAddr);
                ptr->addr = newAddr;
                break;
            case 3:
                printf("Enter the new label: ");
                scanf("%s", newLabel);
                printf("Enter the new address: ");
                scanf("%d", &newAddr);
                strcpy(ptr->label, newLabel);
                ptr->addr = newAddr;
                break;
            default:
                printf("Invalid choice.\n");
            }
            return;
        }
        ptr = ptr->next;
    }
    printf("Label not found.\n");
}

void del()
{
    char label[10];
    struct symbtab *curr = first, *prev = NULL;

    printf("Enter the label to be deleted: ");
    scanf("%s", label);

    while (curr != NULL)
    {
        if (strcmp(curr->label, label) == 0)
        {
            if (curr == first)
            {
                first = first->next;
                if (curr == last)
                    last = NULL;
            }
            else
            {
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
            }
            free(curr);
            size--;
            printf("Label deleted.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Label not found.\n");
}
