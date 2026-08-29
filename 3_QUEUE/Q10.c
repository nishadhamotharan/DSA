#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;

void enqueue(int data, int l)
{
    if (rear == l - 1)
        return;

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;
}

void reverse()
{
    int i = front;
    int j = rear;
    int temp;

    while (i < j)
    {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    int n, t;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        enqueue(t, n);
    }

    printf("Queue:");

    for (int i = front; i <= rear; i++)
    {
        printf(" %d", queue[i]);
    }

    printf("\n");

    reverse();

    printf("Reversed Queue:");

    for (int i = front; i <= rear; i++)
    {
        printf(" %d", queue[i]);
    }

    return 0;
}