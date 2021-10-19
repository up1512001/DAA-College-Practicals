#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int l1,int l2,vector<vector<int>>&dp){

    if(l1==0 || l2==0){
        return dp[l1][l2]=0;
    }
    if(dp[l1][l2]!=-1){
        return dp[l1][l2];
    }
    if(s1[l1-1]==s2[l2-1]){
        return dp[l1][l2] = 1 + LCS(s1,s2,l1-1,l2-1,dp);
    }else{
        return dp[l1][l2] = max(LCS(s1,s2,l1-1,l2,dp),LCS(s1,s2,l1,l2-1,dp));
    }
    return -1;

}

int main(){

    cout<<"Enter Two String :\n";
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            dp[i][j] = -1;
        }
    }
    //memset(dp,-1,sizeof(dp));
    cout<<"Longest Common Subsequence length is :->"<<LCS(s1,s2,s1.size(),s2.size(),dp);

}
