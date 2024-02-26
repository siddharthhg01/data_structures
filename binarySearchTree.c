#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){

struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
temp->data=data;
return temp;
};

struct node* insert(struct node* root,int data){

if(root==NULL){
    return createNode(data);
}
else if(data > root->data){
    root->right=insert(root->right,data);
}
else{
    root->left=insert(root->left,data);
}
return root;
};

void inorder(struct node* root){
if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}

}

void preorder(struct node* root){
if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}
}


void postorder(struct node* root){
if(root!=NULL){

    postorder(root->left);
    postorder(root->right);
     printf("%d ",root->data);

}

}
int main(){
struct node* root=NULL;
root=insert(root,20);
insert(root,10);
insert(root,30);
insert(root,40);
insert(root,70);
insert(root,80);
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
return 0;
}
