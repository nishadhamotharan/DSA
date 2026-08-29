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

void del(struct node **head, int value)
{
    struct node *p1, *p2;

    p1 = *head;

    /* Find the node containing value */
    while (p1 != NULL && p1->data != value)
        p1 = p1->next;

    /* Value not found */
    if (p1 == NULL)
    {
        printf("Invalid Node! ");
        return;
    }

    /* Delete all nodes before p1 */
    while (*head != p1)
    {
        p2 = *head;
        *head = (*head)->next;
        free(p2);
    }
}

int main()
{
    int n, value;
    struct node *head, *temp;

    scanf("%d", &n);

    head = create(n);

    scanf("%d", &value);

    del(&head, value);

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