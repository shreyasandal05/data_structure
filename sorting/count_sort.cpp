#include<iostream>
#include<algorithm>

using namespace std;

void countSort(int arr[],int n){
    int k=0;    //denotes maximum element
    int count[10];   //denotes occurence of every element
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    for(int i=0;i<=k;i++){      //create count array of size k
        count[i]=0;
    }
    for(int i=0;i<n;i++){        //count of every element
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){       //stores sum of count for every position 
        count[i]+=count[i-1]; 
    }
    int output[10];               //output array
    for(int i=n-1;i>=0;i--){   
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){         //assign output to original array 
        arr[i]=output[i];
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//arr[]={1 3 2 3 4 1 6 4 3}