/*
Boyre Moore algorithm (pattern searching algo) uses combination of two approaches:
-Bad character heuristic(Bad match table) 
-Good suffix heuristic
This one is solved using 'Bad character heuristic'.
*/
#include<iostream>
#include<algorithm>
#define MAX 256

using namespace std;

void badMatchTable(string str,int size,int badChar[MAX]){
    for(int i=0;i<MAX;i++){
        badChar[i]=-1;       //bad characters initialise with -1
    }
    for(int i=0;i<size;i++){
        badChar[(int) str[i]]=i; //rest characters with value of last occurenece in the pattern 
    }
}

void bmAlgo(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    int badChar[MAX];
    badMatchTable(pattern,m,badChar); 
    int shift=0;
    while(shift<=(n-m)){
        int j=m-1;
        while(j>=0 && pattern[j]==text[shift+j])
            j--;
        if(j<0){
            cout<<"pattern found at position: "<<shift<<endl;
            shift+=((shift+m)<n)? m-badChar[text[shift+m]] : 1;
        } 
        else{
            shift+=max(1,j-badChar[text[shift+j]]);    
        }
    }
}

int main(){
    string text,pattern;
    cout<<"Enter pattern: ";
    cin>>text;
    cout<<"Enter text: ";
    cin>>pattern;
    bmAlgo(text,pattern);
    return 0;
}