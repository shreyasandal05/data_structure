#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root ,int data){

    if(root==NULL){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
    }
    else
    {
        struct node* newnode;
        if(data<=root->data){
            newnode=insert(root->left,data);
            root->left=newnode;
        }
        else
        {
            newnode=insert(root->right,data);
            root->right=newnode;
        }
    return root;    
    }   
}
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* root=NULL;
    int data;
    int t;

    scanf("%d",&t);
    while(t-- > 0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    inOrder(root);
    return 0;
}