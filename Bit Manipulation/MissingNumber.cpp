/* 
Given a array of n numbers that has values in range[1,n+1].Every number appears exactly once in the array.Hence one number is missing in the array,Find the missing number. 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={1,2,4,5};
    int max=*max_element(a.begin(), a.end());
    int res=0;
    for(auto i=a.begin(); i!=a.end();i++){
        res^=*i;
    }
    for(int i=1;i<=max;i++){
        res^=i;
    }
    cout<<res;
    return 0;
}