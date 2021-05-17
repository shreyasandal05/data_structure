#include<iostream>
#define V 4
using namespace std;

void printSolution(int color[]);

bool isSafe(int **graph,int color[],int v,int c){
    for (int i = 0; i < V; i++){
        if(graph[v][i] && c == color[i])     //if graph[v][i]==1  and  color of adjacent vertex i == c
        return false;
    }
    return true;
}

bool graphColoringUtil(int **graph,int m,int color[],int v){
    if(v==V)      //Base Case
        return true;
        for(int c = 1; c <= m; c++){         //validation of color 'c' for vertex 'v'
            if(isSafe(graph,color,v,c)){
                color[v]=c;

            if(graphColoringUtil(graph,m,color,v+1)==true)  //rest of the vertices
                return true;
             color[v]=0;     //BACKTRACK
            }          
        }
    return false;
}

bool graphColoring(int **graph,int m){
    int color[V];
    for (int i = 0; i < V; i++){
        color[i]=0;
    }
    if(graphColoringUtil(graph,m,color,0)==false){
        cout<<"Solution does not exist";
        return false;
    }
    printSolution(color);
    return true;
}

void printSolution(int color[]){
    cout<<"Solution exists: ";
    for (int i = 0; i < V; i++){
        cout<<color[i]<<" ";
    }
}

int main(){
    int m;
    cout<<"Enter no. of colors: ";
    cin>>m;
    int **graph = new int*[V];
    cout<<"Enter elements of adjacency matrix: \n";
    for (int i = 0; i < V; i++){
        graph[i]=new int[V];
    }
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cin>>graph[i][j];   
        }   
    }
    cout<<endl;
    graphColoring(graph,m);
    return 0;
}
        //  0 1 1 1 
        //  1 0 1 0 
        //  1 1 0 1 
        //  1 0 1 0 