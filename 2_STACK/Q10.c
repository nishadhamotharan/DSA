#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
char stack[MAX][MAX];
int top = -1;
void push(char str[]){
    top++;
    strcpy(stack[top], str);
}
void pop(char str[]){
    strcpy(str, stack[top]);
    top--;
}
void postToPre(char post_exp[]){
    int i;
    char operand1[MAX], operand2[MAX], result[MAX];
    for (i = 0; post_exp[i] != '\0'; i++){
        char ch = post_exp[i];
        if (isalnum(ch)){
            char temp[2];

            temp[0] = ch;
            temp[1] = '\0';

            push(temp);
        }
        else{
            pop(operand2);
            pop(operand1);
            result[0] = ch;
            result[1] = '\0';
            strcat(result, operand1);
            strcat(result, operand2);

            push(result);
        }
    }
    printf("%s", stack[top]);
}
int main(){
    char post_exp[MAX];
    scanf("%s", post_exp);
    postToPre(post_exp);
    return 0;
}