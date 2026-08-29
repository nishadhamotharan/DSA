#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long a[n];
    int F[n], G[n];
    int stack[n];
    int top;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    top = -1;
    for (int i = n - 1; i >= 0; i--){
        while (top >= 0 && a[stack[top]] <= a[i])
            top--;
        if (top == -1)
            F[i] = -1;
        else
            F[i] = stack[top];
        stack[++top] = i;
    }
    top = -1;
    for (int i = n - 1; i >= 0; i--){
        while (top >= 0 && a[stack[top]] >= a[i])
            top--;
        if (top == -1)
            G[i] = -1;
        else
            G[i] = stack[top];
        stack[++top] = i;
    }
    for (int i = 0; i < n; i++){
        if (F[i] == -1 || G[F[i]] == -1)
            printf("-1");
        else
            printf("%lld", a[G[F[i]]]);

        if (i < n - 1)
            printf(" ");
    }
    return 0;
}