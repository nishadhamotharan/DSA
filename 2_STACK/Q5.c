#include <stdio.h>
#include <string.h>
#define MAX 1000
char stack[MAX];
int top = -1;
void push(char ch){
    stack[++top] = ch;
}
char pop(){
    return stack[top--];
}
int empty(){
    return top == -1;
}
int main(){
    char exp[MAX];
    scanf("%s", exp);
    for (int i = 0; i < strlen(exp); i++){
        if (exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']'){
            if (empty()){
                printf("Not Balanced");
                return 0;
            }
            char ch = pop();
            if ((exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '[')){
                printf("Not Balanced");
                return 0;
            }
        }
    }
    if (empty())
        printf("Balanced");
    else
        printf("Not Balanced");
    return 0;
}