#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
void insert_Data(struct node **head){
    struct node *newnode, *temp;
    for (int i = 1; i <= 100; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        if (*head == NULL){
            *head = newnode;
        }
        else{
            temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}
void delete_Alt(struct node **head){
    struct node *a, *b;
    a = *head;
    while (a != NULL && a->next != NULL){
        b = a->next;
        a->next = b->next;
        free(b);
        a = a->next;
    }
}
int main(){
    int n;
    struct node *head = NULL;
    struct node *temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    delete_Alt(&head);
    temp = head;
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    return 0;
}