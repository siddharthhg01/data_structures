#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
void insertAtBeginning(struct node** head,int value){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    (*head)->prev=newNode;
    newNode->next=*head;
    *head=newNode;
}
void deleteNode(struct node** head, int key) {
    struct node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp == *head)
        *head = temp->next;

    free(temp);
}
void displayList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct node* head=NULL;
    int data;
    int pos;
    int choice;

    do{
        printf("Enter \n 1 for insert at left of node \n 2 for delete at given position\n 3 for display:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter data:");
                scanf("%d",&data);
                insertAtBeginning(&head,data);
                break;
            case 2:
                printf("Enter the key:");
                scanf("%d",&pos);
                deleteNode(&head,pos);
                break;
            case 3:
                displayList(head);
                break;
        }
    }while(choice!=0);
}
