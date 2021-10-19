#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt,vector<int> val,int w){

    vector<vector<int>> dp(wt.size()+1,vector<int>(w+1));
    // initialization
    for(int i=0;i<wt.size()+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    // choice diagram code
    for(int i=1;i<wt.size()+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // return
    return dp[wt.size()][w];


}

int main(){

    cout<<"Enter Total size of weight array:->";
    int n;cin>>n;
    vector<int> wt(n),val(n);
    cout<<"Enter Value for weight array:\n";
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter Value for value array:\n";
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter Total size of knapsack:->";
    int w;cin>>w;

    cout<<"Your answer :-> "<<knapsack(wt,val,w);


}
