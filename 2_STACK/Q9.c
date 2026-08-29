#include <stdio.h>
#define MAX 1000
typedef struct {
    int q[MAX];
    int front;
    int rear;
}
Stack;
void push(Stack *s, int val){
    int size, i;
    s->q[s->rear++] = val;
    size = s->rear - s->front - 1;
    for (i = 0; i < size; i++){
        s->q[s->rear++] = s->q[s->front++];
    }
}
int pop(Stack *s){
    if (s->front == s->rear)
        return -1;
    return s->q[s->front++];
}
int main(){
    int n,m;
    int i, val;
    Stack s;
    s.front = 0;
    s.rear = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++){
        scanf("%d", &val);
        push(&s, val);
    }
    if (s.front < s.rear)
        printf("top of element %d\n", s.q[s.front]);
    for (i = 0; i < m; i++){
        pop(&s);
    }
    if (s.front < s.rear)
        printf("top of element %d\n", s.q[s.front]);
    return 0;
}