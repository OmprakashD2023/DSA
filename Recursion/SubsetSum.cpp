#include <bits/stdc++.h>
using namespace std;
int subset(int arr[], int n, int sum)
{
    if (n == 0)
        return sum == 0 ? 1 : 0;
    return subset(arr, n - 1, sum) + subset(arr, n - 1, sum - arr[n - 1]);
}

int main(){
    int arr[]={10,20,15};
    cout<<subset(arr,3,25);
    return 0;
}