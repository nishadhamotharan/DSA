#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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
        r->next = f;
    }
    else
    {
        n->next = f;
        r->next = n;
        r = n;
    }
}

void dequeue()
{
    struct node *t;

    if (f == NULL)
        return;

    t = f;

    if (f == r)
    {
        f = NULL;
        r = NULL;
    }
    else
    {
        f = f->next;
        r->next = f;
    }

    free(t);
}

void display()
{
    struct node *t;

    if (f == NULL)
        return;

    t = f;

    do
    {
        printf("%d", t->data);

        if (t != r)
            printf(" ");

        t = t->next;

    } while (t != f);

    printf("\n");
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

    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}