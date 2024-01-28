#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_at_beg(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

void insert_in_between(struct node** head,int data){
int pos;
printf("Enter the position where to insert data greater than 1\n");
scanf("%d",&pos);
int count=1;
struct node* ptr=*head;
if(*head==NULL){
    printf("No Nodes cant insert at position");
}
while(ptr->next!=NULL){
    if(count==(pos-1)){
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=data;
        new_node->next=ptr->next;
        ptr->next=new_node;
        return;
    }
    count++;
ptr=ptr->next;
if(ptr->next==NULL){
    printf("reached the end node cant insert at specified node \n");
    return;
}
}

}
void insert_at_end(struct node** head,int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
if(*head==NULL){
   *head=new_node;
   return;
}
struct node* ptr=*head;
while(ptr->next!=NULL){
    ptr=ptr->next;
}
ptr->next=new_node;

}
void display(struct node** head) {
    if(*head==NULL){
        printf("No nodes\n");
        return;
    }
    struct node* ptr = *head;
    while (ptr!= NULL) {
        printf("Data = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct node* head = NULL;
    insert_at_beg(&head,10);
    insert_at_end(&head,20);
    insert_at_beg(&head,30);
    insert_at_end(&head,40);
    printf("Before Inserting :\n");
    display(&head);
    printf("After Inserting 50 At the Beginning:\n");
    insert_at_beg(&head,50);
    display(&head);
    printf("After Inserting 80 At the end:\n");
    insert_at_end(&head,80);
    display(&head);
    printf("After Inserting 100 at position 3:\n");
    insert_in_between(&head,100);
    display(&head);
    return 0;
}