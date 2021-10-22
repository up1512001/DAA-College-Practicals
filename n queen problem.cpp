#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &arr,int row,int col){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[row][i]==1){
            return false;
        }
        if(arr[i][col]==1){
            return false;
        }
    }
    for(int i=row+1,j=col+1;i<n && j<n;i++,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=row+1,j=col-1;i<n && j>=0;i++,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    return true;
}

bool helper(vector<vector<int>> &arr,int n,int row=0){
    if(row==n) return true;
    for(int col=0;col<n;col++){
        if(isSafe(arr,row,col)){
            arr[row][col]=1;
            if(helper(arr,n,row+1)){
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main(){

    cout << "Enter board size:->";
    int n;cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));

    helper(arr,n);
    cout<<"Position of queen's on table are:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}