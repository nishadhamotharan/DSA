#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node** head, int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

int main()
{
    int n, data;
    struct Node *head = NULL;
    struct Node *temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertStart(&head, data);
    }
    temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    printf("\n");
    temp = head;

    if (temp != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->prev != NULL)
            printf(" ");

        temp = temp->prev;
    }

    return 0;
}