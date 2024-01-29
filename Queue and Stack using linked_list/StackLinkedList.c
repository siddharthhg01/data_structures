#include <stdio.h>

struct node{
int data;
struct node* next;
};

void push(struct node** head,int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
if(*head==NULL){
    *head=new_node;
    new_node->next=NULL;
}
else{
    new_node->next=*head;
    *head=new_node;
}

}

void pop(struct node** head){

    if(*head==NULL){
        printf("Underflow\n");
    }
    else{

        struct node* ptr=*head;
        *head=ptr->next;
        free(ptr);
    }
}

void display(struct node** head){
    struct node* ptr=*head;
    while(ptr!=NULL){
        printf("data =%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
struct node* head=NULL;
push(&head,20);
push(&head,40);
push(&head,60);
display(&head);
printf("After popping\n");
pop(&head);
display(&head);
return 0;
}
