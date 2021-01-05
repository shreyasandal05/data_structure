// LinkList.cpp
// 30.12.2020
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};
struct node* start=NULL;

void create();
void traverse();
void insert_beg();
void insert_last();
void insert_after();
void delete_beg();
void delete_last();
void delete_after();
void search();
void sorting();
void dup();

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
            case 5:
            delete_beg();
            break;
            case 6:
            delete_last();
            break;
            case 7:
            delete_after();
            break;
            case 8:
            search();
            break;
            case 9:
            sorting();
            break;
            case 10:
            dup();
            break;
            case 11: exit(0);
            default :
            printf("Invalid choice.");
        }
    }
    return 0;
}

void create(){
    struct node *new,*ptr;
    int item;
    char ans='y';
    while(ans=='y'||ans=='Y')
    {
        printf("Enter item value: ",item);
        scanf("%d",&item);
        new=(struct node*)malloc(sizeof(struct node));
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
    new=(struct node*)malloc(sizeof(struct node));
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
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Memory overflow\n");
        return;
    }
    printf("Enter item value: ");
    scanf("%d",&item);
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
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Memory overflow\n");
        return;
    }
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

void delete_last(){
    struct node *ptr,*save;
    if(start==NULL){
        printf("Underflow");
        return;
    }
    if(start->link==NULL){
        ptr=start;
        start=start->link;
    }
    save=start;
    ptr=start->link;
    while(ptr->link!=NULL){
        save=ptr;
        ptr=ptr->link;
    }
    save->link=NULL;
    printf("Deleted node is %d",ptr->info);
    free(ptr);
}

void delete_after(){
    struct node *ptr,*temp;
    int i,pos;
    if(start==NULL){
        printf("\nUnderflow");
        return;
    }
    printf("Enter position ");
    scanf("%d",&pos);
    temp=start;
    ptr=start->link;
    for(i=1;i<pos;i++){
        temp=ptr;
        ptr=ptr->link;
        if(ptr=NULL){
            printf("\nInvalid position");
            return;
        }
    }
    printf("\nDeleted node is: %d",ptr->info);
    temp->link=ptr->link;
free(ptr);
}

void search(){
    struct node *ptr;
    int item,i;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Enter item you want to find: ");
    scanf("%d",&item);
    ptr=start;
    i=1;
    while(ptr!=NULL){
        if(ptr->info==item){
            printf("%d found at %d position",item,i);
            break;
        }
        i++;
        ptr=ptr->link;
    }
    if(ptr=NULL){
        printf("\n%d Item not found",item);
        
    }
}

void sorting(){
    struct node *ptr,*ptr1;
    int temp;
    if(start==NULL){
        printf("List if empty");
        return;
    }
    for(ptr=start;ptr->link!=NULL;ptr=ptr->link){
        for(ptr1=ptr->link;ptr1!=NULL;ptr1=ptr1->link)
        if(ptr->info>ptr1->info){
            temp=ptr->info;
            ptr->info=ptr1->info;
            ptr1->info=temp;
        }
    }
}

void dup(){
    struct node* ptr,*ptr1,*prev,*temp;
    int data;
    if(start==NULL){
        printf("underflow");
        return;
    }
    ptr=start;
    while(ptr!=NULL){
        data=ptr->info;
        prev=ptr;
        ptr1=ptr->link;
        while(ptr1!=NULL){
            if(data==ptr1->info){
                temp=ptr1;
                prev->link=ptr1->link;
                ptr1=ptr1->link;
                free(temp);
            }
            else{
                prev=ptr1;
                ptr1=ptr1->link;
            }
        }
    ptr=ptr->link;
    }
}