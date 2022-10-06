#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,char A,char B,char C){
    if(n==1){
        cout<<"Move 1 Disk From "<<A<<" To "<<C<<endl;
        return;
    }
    towerOfHanoi(n-1,A,C,B);
    cout<<"Move "<<n<<"th Disk From "<<A<<" To "<<C<<endl;
    towerOfHanoi(n-1,B,A,C);
}

int main(){
    int n=3;
    towerOfHanoi(n,'A','B','C');
    return 0;
}