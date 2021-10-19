#include<bits/stdc++.h>
using namespace std;

int static dp[1001][1001];

int MCMmemoized(vector<int>&arr,int i,int j){

    if(i>=j) return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = MCMmemoized(arr,i,k) + MCMmemoized(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn,temp);
    }
    return dp[i][j] = mn;
}

int main(){

    memset(dp,-1,sizeof(dp));

    cout<<"Enter Array Size :->";
    int n;cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Minimum multiplications are :->"<<MCMmemoized(arr,1,n-1)<<"\n";

}
