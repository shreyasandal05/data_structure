#include<stdio.h>
#include<iostream>

using namespace std;

void generateK_aryString(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
    char ch=s[i];
    string restOfString=s.substr(0,i)+s.substr(i+1);
    generateK_aryString(restOfString,ans+ch);
    }
}

int main(){
    string s;
    cin>>s;
    generateK_aryString(s," ");
    return 0;
}