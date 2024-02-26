#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node* next;
};


void reverse(struct node** head){
struct node* nextNode;
struct node* prev=NULL;
struct node* ptr=*head;
while(ptr!=NULL){
    nextNode=ptr->next;
    ptr->next=prev;
    prev=ptr;
    ptr=nextNode;
}
*head=prev;


}


void concat(struct node** head1,struct node** head2){
struct node* ptr=*head1;
while(ptr->next!=NULL){
    ptr=ptr->next;
}

ptr->next=*head2;

}


void sort(struct node** head){
struct node* current=*head;
int temp;
while(current!=NULL){
        struct node* next=current->next;
    while(next!=NULL){
        if(current->data>=next->data){
            temp=current->data;
            current->data=next->data;
            next->data=temp;
        }
        next=next->next;
    }
current=current->next;

}



}

void insert(struct node** head,int data){
    struct node* NewNode=(struct node*)malloc(sizeof(struct node));
    NewNode->data=data;
if(*head==NULL){
    *head=NewNode;
    NewNode->next=NULL;
}
else{
    NewNode->next=*head;
    *head=NewNode;
}
}


void display(struct node** head){
struct node* ptr=*head;
while(ptr!=NULL){
    printf("Data = %d\n",ptr->data);
    ptr=ptr->next;

}


}

int main(){
struct node* head1=NULL;
insert(&head1,80);
insert(&head1,50);
insert(&head1,30);
insert(&head1,100);
insert(&head1,300);
display(&head1);
printf("After reversing\n");
reverse(&head1);
display(&head1);

struct node* head2=NULL;
insert(&head2,36);
insert(&head2,96);
insert(&head2,58);
insert(&head2,20);
printf("Linked List 1\n");
display(&head1);
printf("Linked List 2\n");
display(&head2);
printf("After concatenating List\n");
concat(&head1,&head2);
display(&head1);
printf("Sorting list 2\n");
sort(&head2);
display(&head2);
return 0;
}
