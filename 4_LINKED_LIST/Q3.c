#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node *current;

    // Empty list
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // Insert before head
    if (new_node->data <= (*head_ref)->data)
    {
        current = *head_ref;

        while (current->next != *head_ref)
            current = current->next;

        new_node->next = *head_ref;
        current->next = new_node;
        *head_ref = new_node;
        return;
    }

    // Find correct position
    current = *head_ref;

    while (current->next != *head_ref &&
           current->next->data < new_node->data)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

int main()
{
    int n, data;
    struct Node *head = NULL;
    struct Node *new_node;
    struct Node *temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);

        new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->next = NULL;

        sortedInsert(&head, new_node);
    }

    temp = head;

    if (temp != NULL)
    {
        do
        {
            printf("%d", temp->data);

            temp = temp->next;

            if (temp != head)
                printf(" ");

        } while (temp != head);
    }

    return 0;
}