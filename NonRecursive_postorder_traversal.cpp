#include<stdio.h>
#include<stack>
#include<stdlib.h>
#include<iostream>

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


void postOrder(struct BinaryTreeNode* root){
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode*> s1,s2;
    s1.push(root);
    BinaryTreeNode* node;
    while(!s1.empty()){
        node=s1.top();
        s1.pop();
        s2.push(node);

        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }
    while(!s2.empty()){
        node=s2.top();
        s2.pop();
        cout<<node->data<<" ";
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
	postOrder(root);
	return 0;
}
