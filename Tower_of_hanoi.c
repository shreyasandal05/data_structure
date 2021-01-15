#include<stdio.h>
#include<conio.h>

void towerOfHanoi(int n,char beg,char end,char aux){
    if(n==1){
        printf("\nMove 1 disk from %c to %c",beg,end);
        return;
    }
    towerOfHanoi(n-1,beg,aux,end);
        printf("\nMove %d disk from %c to %c",n,beg,end);
    towerOfHanoi(n-1,aux,end,beg);    
}

int main(){
    int n;
    printf("Enter no. of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n,'A','C','B');
    return 0;
}
