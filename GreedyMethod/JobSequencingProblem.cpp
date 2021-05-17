#include<iostream>   
#include<algorithm>     //std::sort()

using namespace std;

struct Job{
    char jobId;
    int deadline,profit;
    
    void getjobId(){
        cin>>jobId;
    }
    void getdeadline(){
        cin>>deadline;
    }
    void getprofit(){
        cin>>profit;
    }
};

int compare(Job a,Job b){
    return(a.profit>b.profit);
}

void jobSequencing(Job arr[],int n){
    sort(arr,arr+n,compare);       //sorting elements from beginning of array upto length n
//the parameters of sort are:              
// __first – An iterator.
// __last – Another iterator.
// __comp – A comparison functor.
                         
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++){
        slot[i]=false;        //slots are empty
    }
    for(int i=0;i<n;i++){      //for every job...
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--){   //find free slot
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){     //print the result
        if(slot){
            cout<<arr[result[i]].jobId<<" ";
        }
    }

}

int main(){
    int n;
    cout<<"Enter no. of jobs: ";
    cin>>n;
    Job arr[n];
    cout<<"Enter further details: ";
    for(int i=0;i<n;i++){
        arr[i].getjobId();
        arr[i].getdeadline();
        arr[i].getprofit();
    }
    jobSequencing(arr,n);
    return 0;
}

// further details---> a 2 100   
// b 1 19
// c 2 27
// d 1 25
// e 3 15   