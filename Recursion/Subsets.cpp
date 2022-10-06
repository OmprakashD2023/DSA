#include<bits/stdc++.h>
using namespace std;

void subsets(string s,string cur=" ",int i=0){
    if(s.length() == i){
        cout<<cur<<endl;
        return;
    }
    subsets(s,cur,i+1);
    subsets(s,cur+s[i],i+1);
}

int main(){
    string s="abc";
    subsets(s);
    return 0;
}

