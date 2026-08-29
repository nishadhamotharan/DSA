#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d)
{
    struct node *n;

    n = (struct node*)malloc(sizeof(struct node));

    n->data = d;
    n->next = NULL;

    if (f == NULL)
    {
        f = n;
        r = n;
    }
    else
    {
        r->next = n;
        r = n;
    }
}

void dequeue()
{
    struct node* t;

    if (f == NULL)
        return;

    t = f;

    printf("%d\n", t->data);

    f = f->next;

    if (f == NULL)
        r = NULL;

    free(t);
}

int main()
{
    int n, d;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        enqueue(d);
    }

    while (f != NULL)
    {
        dequeue();
    }

    return 0;
}