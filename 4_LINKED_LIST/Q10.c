#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void del(struct node **head, int d)
{
    struct node *temp;

    for (int i = 0; i < d; i++)
    {
        if (*head == NULL)
            return;

        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    int n, d;
    struct node *head, *temp;

    scanf("%d", &n);

    head = create(n);

    scanf("%d", &d);

    del(&head, d);

    printf("Linked List:->");

    temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf("->");

        temp = temp->next;
    }

    return 0;
}