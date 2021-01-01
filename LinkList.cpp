// LinkList.cpp
// 30.12.2020
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* start=NULL;

int main(){
    int choice;
    create();
    while(1){
        printf("\n\nMENU\n\n");
        printf("1.Traverse\n");
        printf("2.Insert at beg\n");
        printf("3.Insert at last\n");
        printf("4.Insert after\n");
        printf("5.Delete at beg\n");
        printf("6.Delete at last\n");
        printf("7.Delete after\n");
        printf("8.Search\n");
        printf("9.Sorting\n");
        printf("10.Duplicate\n");
        printf("11.Exit\n");

        printf("Enter your choice: ",choice);
        scanf("%d",&choice);
        switch(choice){
            case 1:
            traverse();
            break;
            case 2:
            insert_beg();
            break;
            case 3:
            insert_last();
            break;
            case 4:
            insert_after();
            break;
            default :
            printf("Invalid choice.");
        }
    }
    return 0;
}

void create(){
    struct node *new,*ptr;
    int item;
    char ans;
    while(ans=='y'||ans=='Y')
    {
        printf("Enter item value: ",item);
        scanf("%d",&item);
        new=(struct node*)malloc(sizeof(struct node*));
        if(new==NULL){
            printf("Memory overflow\n");
            return;
        }
        new->info=item;
        new->link=NULL;
        if(start==NULL){
            start=new;
        }
        else
        {
            ptr=start;
            while(ptr->link!=NULL)
                ptr=ptr->link;
                ptr->link=new;
        }        
        printf("Do you want to add more nodes? ");
        scanf(" %c",&ans);     
    }

}

void traverse(){
    struct node* ptr;
    if(start==NULL){
        printf("List is empty");
        return;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("\t%d",ptr->info);
            ptr=ptr->link;
        }
    }
    
}

void insert_beg(){
    struct node *new;
    int item;
    new=(struct node*)malloc(sizeof(struct node*));
    if(new==NULL){
        printf("memory overflow\n");
        return;
    }
    printf("Enter item value: ");
    scanf("%d",&item);
    new->info=item;
    new->link=start;
    start=new;
}

void insert_last(){
    struct node* new,*ptr;
    int item;
    new=(struct node*)malloc(sizeof(struct node*));
    if(new==NULL){
        printf("Memory overflow\n");
        return;
    }
    printf("Enter item value: ");
    scanf("%d",item);
    new->info=item;
    new->link=NULL;
    if(start==NULL){
        start=new;
    }
    else{
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    }

}

void insert_after(){
    struct node* new,*ptr;
    int item,i,pos;
    new=(struct node*)malloc(sizeof(struct node*));
    if(new==NULL)[
        printf("Memory overflow\n");
        return;
    ]
    printf("Enter item value: ");
    scanf("%d",&item);
    printf("Enter position after which you want to insert: ");
    scanf("%d",&pos);
    new->info=item;
    i=1,ptr=start;
    while(i<pos){
        if(ptr==NULL){
            printf("Invalid input\n");
            return;
        }
        ptr=ptr->link;
        i++;
    }
    new->link=ptr->link;
    ptr->link=new;
}

void delete_beg(){
    struct node* temp;
    if(start==NULL){
        printf("Underflow\n");
        return;
    }
    temp=start;
    start=start->link;
    printf("Deleted node is %d",temp->info);
    free(temp);
}

