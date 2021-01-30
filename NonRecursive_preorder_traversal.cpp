#include<stdio.h>
#include<stack>
#include<stdlib.h>
#include<iostream>
#define MAXSTK 5

using namespace std;

struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
	BinaryTreeNode(int data){
		this->data=data;
		left=right=NULL;
	}
};

struct BinaryTreeNode* insert(struct BinaryTreeNode* root,int data){
    if(root==NULL){
        struct BinaryTreeNode* node=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else
    {
        struct BinaryTreeNode* newnode;
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

void preOrder(struct BinaryTreeNode* root){
    if(root==NULL){         //base case
        return;
    }
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);
    while(nodeStack.empty()==false){
        struct BinaryTreeNode* node=nodeStack.top();
        cout<<node->data<<" ";
        nodeStack.pop();

        if(node->right)
            nodeStack.push(node->right);
        if(node->left)
            nodeStack.push(node->left);
    }
}

int main(){
	int t;
	cin>>t;
	struct BinaryTreeNode* root=NULL;
    int data;
	while(t--){
		scanf("%d",&data);
        root=insert(root,data);
	}	
	preOrder(root);
	return 0;
}
