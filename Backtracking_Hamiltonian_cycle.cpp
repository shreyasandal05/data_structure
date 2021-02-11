#include<stdio.h>
#include<iostream>
#define V 5

using namespace std;

void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos){
    if(graph[path[pos-1]][v]==0)        //not adjacent
        return false;
    for(int i=0;i<pos;i++)
        if(path[i]==v)         //repeating 
        return false;
    return true;    
}

bool hamiltonianCycleUtility(bool graph[V][V], int path[], int pos){ //aid for finding solution 
    if(pos==V){                                                        //base case
        if(graph[path[pos-1]][path[0]]==1)//edge from last vertex to first vertex exists
            return true;
        else
            return false;
    }
for(int v=1;v<V;v++){                  
    if(isSafe(v,graph,path,pos)){
        path[pos]=v;       //mark as visited
    if(hamiltonianCycleUtility(graph,path,pos+1)==true)
    return true;
    path[pos]=-1;    //mark as non visited - ( BACKTRACKING )
    }
}
return false;
}

bool hamCycle(bool graph[V][V]){
    int *path= new int [V];
    for(int i=0;i<V;i++)
    path[i]=-1;     //initialise
    path[0]=0;
    if(hamiltonianCycleUtility(graph,path,1)==false){
        cout<<"Solution does not exist";
        return false;
    }
    printSolution(path);
    return true;
}

void printSolution(int path[]){
    cout<<"Solution exists: ";
    for(int i=0;i<V;i++)
    cout<<path[i]<<" ";
    cout<<path[0];
    cout<<endl;
}

int main(){
    
    // bool graph[V][V] = {{0, 1, 0, 1, 0},  
    //                     {1, 0, 1, 1, 1},  
    //                     {0, 1, 0, 0, 1},  
    //                     {1, 1, 0, 0, 1},  
    //                     {0, 1, 1, 1, 0}};  
        
    // hamCycle(graph);

// bool **graph=new bool*[V];
//     for(int i=0;i<V;i++){            //input for matrix
//         graph[i]=new bool[V];
//     }
//     for(int i=0;i<V;i++){
//         for(int j=0;j<V;j++){
//             cin>>graph[i][j];
//         }
//     }
//     cout<<endl;

bool graph[V][V];
cout<<"\nEnter value for adjacency matrix";
for(int i=0;i<V;i++){
    for(int j=0;j<V;j++)
    cin>>graph[i][j];
    }

    hamCycle(graph);
    return 0;
}

//Solution does not exist
/* 0 1 0 1 0
   1 0 1 1 1
   0 1 0 0 1       
   1 1 0 0 0 
   0 1 1 0 0 */

//Solution exists
/* 0 1 0 1 0
   1 0 1 1 1
   0 1 0 0 1
   1 1 0 0 1
   0 1 1 1 0 */