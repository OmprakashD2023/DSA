#include<bits/stdc++.h>
using namespace std;
int secondLargest(int arr[],int n){
    int res=-1,largest=0;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            res=largest;
            largest=arr[i];
        }
        else if(arr[i]!=largest){
            if(res==-1||largest>res){
                res=arr[i];
            }
        }
    }
    return res;
}
int main(){
    int arr[]={1,3,15,2,7};
    cout<<secondLargest(arr,5);
    return 0;
}