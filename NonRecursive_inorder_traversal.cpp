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


void inOrder(struct BinaryTreeNode* root){
	stack<BinaryTreeNode*> st;
	BinaryTreeNode* current=root;
	while(current!=NULL||st.empty()==false){
		while(current!=NULL){
			st.push(current);
			current=current->left;
		}
		current=st.top();
		st.pop();
		cout<<current->data<<" ";
		current=current->right;
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
	inOrder(root);
	return 0;
}



