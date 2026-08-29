#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    unsigned pageNumber;
    struct QNode *prev;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    int numberOfFrames;
    int count;
    QNode *front;
    QNode *rear;
} Queue;

QNode* newNode(unsigned pageNumber)
{
    QNode *n;

    n = (QNode*)malloc(sizeof(QNode));

    n->pageNumber = pageNumber;
    n->prev = NULL;
    n->next = NULL;

    return n;
}

Queue* createQueue(int numberOfFrames)
{
    Queue *q;

    q = (Queue*)malloc(sizeof(Queue));

    q->numberOfFrames = numberOfFrames;
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void moveToFront(Queue *q, QNode *node)
{
    if (node == q->front)
        return;

    if (node == q->rear)
        q->rear = node->prev;

    if (node->prev != NULL)
        node->prev->next = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    node->next = q->front;
    node->prev = NULL;

    if (q->front != NULL)
        q->front->prev = node;

    q->front = node;

    if (q->rear == NULL)
        q->rear = node;
}

void refer(Queue *q, unsigned pageNumber)
{
    QNode *temp;

    temp = q->front;

    while (temp != NULL)
    {
        if (temp->pageNumber == pageNumber)
        {
            moveToFront(q, temp);
            return;
        }

        temp = temp->next;
    }

    if (q->count == q->numberOfFrames)
    {
        temp = q->rear;

        q->rear = temp->prev;

        if (q->rear != NULL)
            q->rear->next = NULL;
        else
            q->front = NULL;

        free(temp);

        q->count--;
    }

    temp = newNode(pageNumber);

    temp->next = q->front;

    if (q->front != NULL)
        q->front->prev = temp;
    else
        q->rear = temp;

    q->front = temp;

    q->count++;
}

void displayQueue(Queue *q)
{
    QNode *temp = q->front;

    while (temp != NULL)
    {
        printf("%u", temp->pageNumber);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int n, frames;
    unsigned page;

    scanf("%d %d", &n, &frames);

    Queue *q = createQueue(frames);

    for (int i = 0; i < n; i++)
    {
        scanf("%u", &page);
        refer(q, page);
    }

    displayQueue(q);

    return 0;
}