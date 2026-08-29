#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void display(struct node *h)
{
    struct node *temp;

    if (h == NULL)
        return;

    temp = h;

    do
    {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != h)
            printf("->");

    } while (temp != h);

    printf("->[h]\n");
}

int main()
{
    int n, data;
    struct node *odd = NULL, *even = NULL;
    struct node *ot = NULL, *et = NULL;
    struct node *temp;
    int pos = 1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }

    temp = head;

    do
    {
        struct node *newnode;

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = temp->data;

        if (pos % 2 == 1)
        {
            if (odd == NULL)
            {
                odd = newnode;
                ot = newnode;
            }
            else
            {
                ot->next = newnode;
                ot = newnode;
            }
        }
        else
        {
            if (even == NULL)
            {
                even = newnode;
                et = newnode;
            }
            else
            {
                et->next = newnode;
                et = newnode;
            }
        }

        pos++;
        temp = temp->next;

    } while (temp != head);
    if (ot != NULL)
        ot->next = odd;

    if (et != NULL)
        et->next = even;

    printf("Complete linked list:\n");
    display(head);

    printf("Odd:\n");
    display(odd);

    printf("Even:\n");
    display(even);

    return 0;
}