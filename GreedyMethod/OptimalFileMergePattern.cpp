#include<iostream>  //std::cout
#include<functional> //std::greater
#include<queue>   //std::priority_queue<>
using namespace std;

int minComputation(int files[],int n){
    priority_queue<int, vector<int>, greater<int>> pq;    //min heap implementation
    for(int i=0;i<n;i++){
        pq.push(files[i]);
    }
    int count=0;
    while(pq.size()>1){
        int first_smallest=pq.top();
        pq.pop();
        int second_smallest=pq.top();
        pq.pop();
        int temp=first_smallest+second_smallest;
        count+=temp;
        pq.push(temp);
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter no. of files: ";
    cin>>n;
    int files[n];
    cout<<"Enter file sizes: ";
    for(int i=0;i<n;i++){
        cin>>files[i];
    }
    cout << "Minimum Computations = "<<minComputation(files,n);
    return 0;
}
//files[]={2 3 4 5 6 7}