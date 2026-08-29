#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;
}

void disp()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);

        if (i < rear)
            printf(" ");
    }
}

int main()
{
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);

        enqueue(data);

        disp();
        printf(" Enqueuing %d\n", data);
    }

    disp();
    printf("\n");

    return 0;
}