#include<bits/stdc++.h>
using namespace std;
int josephus(int n,int k){
    return josephusExtended(n,k)+1;
}

int josephusExtended(int n,int k){
    if(n==1)
        return 0;
    return (josephus(n-1,k)+k)%n;
}

int main(){
    int n,k;
    cout<<"Enter the number of persons : ";
    cin>>n;
    cout<<"Enter the interval to pass the gun : ";
    cin>>k;
    cout<<josephus(n,k);
    return 0;
}