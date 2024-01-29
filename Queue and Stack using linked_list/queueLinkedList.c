#include <stdio.h>

struct node{
int data;
struct node* next;
};

void enqueue(struct node** head,struct node** tail, int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
if(*head==NULL){
    *head=new_node;
    *tail=new_node;
    new_node->next=NULL;

}
else{
        struct node* ptr=*tail;
        ptr->next=new_node;
    *tail=new_node;
    new_node->next=NULL;
}
}


void dequeue(struct node** head,struct node** tail){

if(head==NULL){
    printf("Underflow\n");
}
else if(*head==*tail){
    *head=NULL;
    *tail=NULL;
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
struct node* tail=NULL;
enqueue(&head,&tail,20);
enqueue(&head,&tail,30);
enqueue(&head,&tail,40);
enqueue(&head,&tail,50);
display(&head);
printf("After deleting\n");
dequeue(&head,&tail);
display(&head);
return 0;
}
