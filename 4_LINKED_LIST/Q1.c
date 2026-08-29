#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n)
{
    struct node *newnode, *temp;
    int data;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);

        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

void del(int d)
{
    struct node *p1, *p2;

    while (head != NULL && head->data == d)
    {
        p1 = head;
        head = head->next;
        free(p1);
    }

    if (head == NULL)
        return;

    p2 = head;

    while (p2->next != NULL)
    {
        if (p2->next->data == d)
        {
            p1 = p2->next;
            p2->next = p1->next;
            free(p1);
        }
        else
        {
            p2 = p2->next;
        }
    }
}

int main()
{
    int n, d;
    struct node *temp;

    scanf("%d", &n);

    create(n);

    scanf("%d", &d);

    del(d);

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