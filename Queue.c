#include<stdio.h>
#include<stdlib.h>
#define MAXQ 5

int front=-1;
int rear=-1;
int queue[5];

void insert();
void delete();
void traverse();

int main(){
    int choice,item;
    while(1){
        printf("\n-----MENU------\n");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Traverse");
        printf("\n4.Exit");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            traverse();
            break;
            case 4:
            exit(0);
            default:
            printf("\nInvalid choice");
        }
    }
}

void insert(){
    int item;
    if(rear==MAXQ-1){
        printf("\nOverflow");
        return;
    }
    else{
    if(front==-1)
        front=0;
        printf("Insert element in the queue");
        scanf("%d",&item);
        rear=rear+1;
        queue[rear]=item;
    }
}

void delete(){
    int item;
    if(front==-1 || front>rear){
        printf("\nUnderflow");
        return;
    }
    else
    {
        printf("\nDeleted item is %d",queue[front]);
        front=front+1;
    }
}

void traverse(){
    int i;
    if(front==-1){
        printf("Empty queue");
        return;
    }
    i=front;
    while(i<=rear){
        printf("\t%d",queue[i]);
        i++;
    }
}
