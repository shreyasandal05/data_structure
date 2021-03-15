#include<iostream>
#include<algorithm>
using namespace std;

// void swap(int arr[],int x,int y){
//     int temp=arr[x];
//     arr[x]=arr[y];
//     arr[y]=temp; 
// }

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low,j=high+1;
    do{
        do
        i++;
        while(arr[i]<pivot && i<=high);

        do
        j--;
        while(pivot<arr[j]);

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while(i<j);

    arr[low]=arr[j];
    arr[j]=pivot;
    
    return j;
} 

void quickSort(int arr[],int low,int high){
    if(low<high){
        int j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"\nThe sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}