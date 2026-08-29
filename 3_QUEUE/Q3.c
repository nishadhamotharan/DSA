#include <stdio.h>

int queue[100];
int front = 0;
int rear = -1;

void enqueue(int data)
{
    rear++;
    queue[rear] = data;
}

void dequeue()
{
    if (front < rear)
    {
        front++;

        for (int i = front; i <= rear; i++)
        {
            printf("%d", queue[i]);

            if (i < rear)
                printf(" ");
        }

        printf("\n");
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
    }

    printf("Dequeuing elements:\n");

    while (front < rear)
    {
        dequeue();
    }

    return 0;
}