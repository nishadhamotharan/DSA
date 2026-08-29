#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d)
{
    struct node *new_n;
    new_n = (struct node*)malloc(sizeof(struct node));

    new_n->data = d;
    new_n->next = NULL;

    if (front == NULL)
    {
        front = new_n;
        rear = new_n;
    }
    else
    {
        rear->next = new_n;
        rear = new_n;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        return;
    }

    struct node *temp = front;
    front = front->next;

    free(temp);

    if (front == NULL)
        rear = NULL;
}

void print()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("No data in the queue.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }

    print();

    dequeue();

    print();

    return 0;
}