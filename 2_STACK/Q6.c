#include <stdio.h>
void calculateSpan(int price[], int n, int S[]){
    int stack[n];
    int top = -1;
    S[0] = 1;
    stack[++top] = 0;
    for (int i = 1; i < n; i++){
        while (top >= 0 && price[stack[top]] <= price[i]){
            top--;
        }
        if (top == -1)
            S[i] = i + 1;
        else
            S[i] = i - stack[top];

        stack[++top] = i;
    }
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);

        if (i < n - 1)
            printf(" ");
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int price[n];
    int S[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &price[i]);
    }
    calculateSpan(price, n, S);
    printArray(S, n);
    return 0;
}