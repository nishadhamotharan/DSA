#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct {
    node *top;
} mystack;
void push(int data, mystack *ms) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = ms->top;
    ms->top = newNode;
}
int pop(mystack *ms) {
    if (ms->top == NULL) {
        return -1;
    }
    node *temp = ms->top;
    int data = temp->data;
    ms->top = ms->top->next;
    free(temp);
    return data;
}
void merge(mystack *ms1, mystack *ms2) {
    while (ms1->top != NULL) {
        printf("%d ", pop(ms1));
    }
    while (ms2->top != NULL) {
        printf("%d ", pop(ms2));
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    mystack s1;
    mystack s2;
    s1.top = NULL;
    s2.top = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(data, &s1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        push(data, &s2);
    }

    merge(&s1, &s2);

    return 0;
}