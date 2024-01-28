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

void delete_at_beg(struct node** head){
    if(*head==NULL){
        printf("underflow\n");
    }
   else{
    struct node* temp=*head;
    *head=temp->next;
    free(temp);
   }

}

void delete_at_end(struct node** head){
if(*head==NULL){
        printf("underflow\n");
        return;
    }

struct node* ptr=*head;
struct node* prev;
if(ptr->next==NULL){
    *head=NULL;
    free(ptr);
    return;
}
while(ptr->next!=NULL){
    prev=ptr;
    ptr=ptr->next;
}
prev->next=NULL;
free(ptr);
}

void delete_element(struct node** head){
int element;
printf("Enter the element to delete\n");
scanf("%d",&element);
if(*head==NULL){
    printf("Underflow\n");
    return;
}
struct node* ptr=*head;
struct node* prev;
if(ptr->next==NULL){
    if(ptr->data==element){
        free(ptr);
        *head=NULL;
    }
}
else{
while(ptr!=NULL){

    if(ptr->data==element){
        if(ptr->next==NULL){
            prev->next=NULL;
            free(ptr);
            return;
        }
        else{
            prev->next=ptr->next;
            free(ptr);
            return;
        }
    }
    prev=ptr;
    ptr=ptr->next;
    if(ptr==NULL){
        printf("element not found\n");
    }
}
}}
int main() {
    struct node* head = NULL;
    printf("Before Deleting :\n");
    insert_at_beg(&head,10);
    insert_at_beg(&head,20);
    insert_at_beg(&head,30);
     insert_at_beg(&head,40);
     insert_at_beg(&head,50);
     display(&head);
     printf("After Deleting an element at beginning:\n");
    delete_at_beg(&head);
    display(&head);
    printf("After Deleting an element at end:\n");
     delete_at_end(&head);
    display(&head);
    printf("After Deleting an element at where data=30 :\n");
     delete_element(&head);
    display(&head);
    return 0;
}