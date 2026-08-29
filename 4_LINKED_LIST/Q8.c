#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **head, int data)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

int main()
{
    int n, data;
    struct node *head = NULL;
    struct node *slow, *fast;
    struct node *second, *temp;
    struct node *first;
    struct node *newhead = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        create(&head, data);
    }

    printf("Link list data:");
    print(head);

    /* Find middle */
    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* For even number of nodes, slow is second half */
    second = slow;

    /* Find the node before second half */
    temp = head;

    while (temp->next != second)
        temp = temp->next;

    temp->next = NULL;

    /* Reverse second half */
    second = reverse(second);

    /* Merge alternately */
    first = head;

    while (first != NULL && second != NULL)
    {
        struct node *fnext = first->next;
        struct node *snext = second->next;

        create(&newhead, first->data);
        create(&newhead, second->data);

        first = fnext;
        second = snext;
    }

    while (first != NULL)
    {
        create(&newhead, first->data);
        first = first->next;
    }

    while (second != NULL)
    {
        create(&newhead, second->data);
        second = second->next;
    }

    printf("Link list data after fold:");
    print(newhead);

    return 0;
}