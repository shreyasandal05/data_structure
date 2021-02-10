#include<stdio.h>
#include<stdlib.h>

struct data{
    int key;
    int value;
};

struct data *array;
int capacity = 10;
int size = 0;

// gives unique hashcode to given key
int hashcode(int key){
    return (key % capacity);
}

// to check if given input is prime or not
int if_prime(int n){
    int i;
    if( n== 1 || n == 0){
        return 0;
    }
    for(i=2; i<n/2; i++){
        if(n % i == 0){
            return 0;
        }  
    }
    return 1;
}

// returns prime no. just greater than array capacity
int get_prime(int n){     //using size as prime no. will reduce occurence of collision
    if(n % 2 == 0){
        n++;
    }
    while(!if_prime(n)){
        n+=2;
    }
    return n;
}

void init_array(){
    int i;
    capacity=get_prime(capacity);
    array=(struct data*)malloc(capacity*sizeof(struct data));
    for(i=0; i<capacity; i++){
        array[i].key=0;
        array[i].value=0;
    }
}

// insert hash key in hash table
void insert(int key, int value){
    int index = hashcode(key);
    if(array[index].value == 0){
        /*key is not present, insert it*/
        array[index].key=key;
        array[index].value=value;
        size++;
        printf("\nkey %d has been inserted",key);
    }
    else if(array[index].key == key){
        /*updating existing key*/
        printf("\nkey %d is already present, hence updating its value",key);
        array[index].value=value;
    }
    else
    {
        /*key cannot be inserted as other value is already present */
        printf("\nElement cannot be inserted!");
    }
}

void remove_element(int key){
    int index = hashcode(key);
    if(array[index].value == 0){
        printf("\nThis key does not exist.");
    }
    else{
        array[index].key=0;
        array[index].value=0;
        size--;
        printf("\nKey %d has been removed.",key);
    }
}

void display(){
    int i;
    for(i=0; i<capacity; i++){
        if(array[i].value == 0){
            printf("\nArray[%d] has no elements",i);
        }
        else{
            printf("\nArray[%d] -> %d key, %d value:",i,array[i].key,array[i].value);
        }
    }
}

int size_of_hashtable(){
    return size;
}

int main(){
    int choice,key,value,n;
    int c=0;
    init_array();
   do{
        printf("\nMENU\n");
        printf("\n1.Insert\n2.Remove\n3.Check size\n4.Display");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the key you want to insert: ");
            scanf("%d",&key);
            printf("\nEnter value you want to insert: ");
            scanf("%d",&value);
            insert(key, value);
            break;

            case 2:
            printf("Enter the key you want to delete:");
            scanf("%d",&key);
            remove_element(key);
            break;
            
            case 3:
            n = size_of_hashtable();
            printf("\nThe size of hash table is: %d ",n);
            break;

            case 4:
            display();
            break;

            default:
            printf("\nInvalid choice");
        }
        printf("\nDo you want to continue?(press 1 to continue): ");
        scanf("%d",&c);
    } while(c==1);
}