#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int GetNth(struct node *head, int index)
{
    struct node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (i == index)
            return temp->data;

        temp = temp->next;
        i++;
    }

    return -1;
}

int main()
{
    int n, index;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

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

    scanf("%d", &index);

    printf("Linked list: ");
    int arr[n];
    temp = head;

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\n");

    printf("Node at index=%d:%d", index, GetNth(head, index));

    return 0;
}