#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 5

int top=-1;
void push(int [],int );
void pop(int []);
void traverse(int []);

int main(){
    int stack[5];
    int choice,item;
    while(1){
        printf("\n-----MENU-----\n");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Traverse");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter item you want to push");
            scanf("%d",&item);
            push(stack,item);
            break;
            case 2:
            pop(stack);
            break;
            case 3:
            traverse(stack);
            break;
            case 4: 
            exit(0);
            default:
            printf("\nInvalid choice");
        }
    }
    
}

void push(int stack[],int item){
    if(top==MAXSTK-1){
        printf("Overflow");
        return;
    }
    top=top+1;
    stack[top]=item;
}

void pop(int stack[]){
    int item;
    if(top==-1){
        printf("Underflow");
        return;
    }
    item=stack[top];
    top=top-1;
    printf("\nItem popped is: %d",item);
}

void traverse(int stack[]){
    int i;
    if(top==-1){
        printf("\nStack empty");
        return;
    }
    i=top;
    while(i>=0){
        printf("\t%d",stack[i]);
        i--;
    }
}