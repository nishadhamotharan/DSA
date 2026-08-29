#include <stdio.h>
#define MAX 5
typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} twoStacks;
void push1(int x, twoStacks *s) {
    s->arr[++s->top1] = x;
}
void push2(int x, twoStacks *s) {
    s->arr[--s->top2] = x;
}
int pop1(twoStacks *s) {
    return s->arr[s->top1--];
}
int pop2(twoStacks *s) {
    return s->arr[s->top2++];
}
int main() {
    int n;
    scanf("%d", &n);
    twoStacks s;
    s.top1 = -1;
    s.top2 = MAX;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (i % 2 == 0) {
            push1(x, &s);
        } else {
            push2(x, &s);
        }
    }
    printf("Popped element from stack1 is:%d\n", pop1(&s));
    printf("Popped element from stack2 is:%d\n", pop2(&s));

    return 0;
}