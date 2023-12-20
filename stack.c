#include <stdio.h>
int top=-1;
void push(int arr[],int value){
if(top>4){
    printf("\nstack overflow cant insert the element");
}
else{
++top;
arr[top]=value;
printf("\nSuccessfully pushed the element %d",arr[top]);
}
}
void pop(int arr[]){
if(top==-1){
    printf("\nstack underflow no element to pop\n");
}
else{
    printf("\none Element was popped %d\n",arr[top]);
    top--;
}
}
void display(int arr[]){
    printf("The elements are \n");
for(int i=top;i>=0;i--){
    printf("%d\n",arr[i]);
}
}
void main(){
    int stack[5];
    void operations(){
    int choice;
    int value;
    printf("\n Enter your choice \n");
    printf("Enter 1 to push\n Enter 2 to pop\n Enter 3 to display\n Enter 4 for exit\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter the element to push ");
    scanf("%d",&value);
    push(stack,value);
    operations();
    break;
case 2:
    pop(stack);
    operations();
    break;

case 3:
    display(stack);
    operations();
    break;
case 4:
    printf("You have exited");
    }
}
    operations();
}
