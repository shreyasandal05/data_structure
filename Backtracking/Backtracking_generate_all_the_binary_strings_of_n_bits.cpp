#include<stdio.h>
#include<iostream>

using namespace std;

void printTheArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void generateBinaryString(int n,int arr[],int i){
    if(i==n){
        printTheArray(arr,n);
        return;
    }
    arr[i]=0;
    generateBinaryString(n,arr,i+1);
    arr[i]=1;
    generateBinaryString(n,arr,i+1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    generateBinaryString(n,arr,0);
    return 0;
}
