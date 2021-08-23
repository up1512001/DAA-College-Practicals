#include<bits/stdc++.h>
using namespace std;

class Practical5{

public:
    vector<int> arr;
    Practical5(vector<int>&a){
        this->arr = a;
    }
    int partition(vector<int>&arr,int i,int j){

        int pivot = arr[j];
        int low = i-1;
        for(int k=i;k<j;k++){
            if(arr[k]<=pivot){
                low++;
                swap(arr[k],arr[low]);
            }
        }
        swap(arr[low+1],arr[j]);
        return low+1;

    }
    void QuickSort(vector<int>&arr,int i,int j){
        if(i<j){
            int pivot = partition(arr,i,j);
            QuickSort(arr,i,pivot-1);
            QuickSort(arr,pivot+1,j);
        }
        return;
    }
    void BinarySearch(vector<int>&arr,int val){

        int i=0,j=arr.size()-1;
        while(i<j){
            int mid = i+(j-i)/2;
            if(arr[mid]==val){
                cout<<"value found at "<<mid+1<<" index...\n";
                return;
            }else if(arr[mid]<val){
                i=mid+1;
            }else{
                j=mid;
            }
        }
        cout<<"value NOT found ...\n";
        return;
    }
    void printArray(vector<int>&arr){

        //cout<<"Printing array\n";
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

};

int main(){

    cout<<"1)Quick Sort\n2)Binary Search\n";
    cout<<"Enter Choice:->";
    int c;cin>>c;

    switch(c){
    case 1:{
        cout<<"Enter Array for sorting ...\n";
        cout<<"Enter Size of Array:->";
        int n;cin>>n;
        vector<int> arr(n,0);
        cout<<"Enter Array:\n";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Practical5 o1(arr);
        cout<<"Before Sorting: ";
        o1.printArray(o1.arr);
        o1.QuickSort(o1.arr,0,n-1);
        cout<<"After Sorting: ";
        o1.printArray(o1.arr);
        break;
    }
    case 2:{
        cout<<"Enter Sorted Array:\n";
        cout<<"Enter Size of Array:->";
        int n;cin>>n;
        vector<int> arr(n,0);
        cout<<"Enter Array:\n";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Enter Value you want to find:->";
        int val;cin>>val;
        Practical5 o2(arr);
        sort(begin(o2.arr),end(o2.arr));
        o2.BinarySearch(o2.arr,val);
        break;
    }
    default:
        cout<<"Enter Valid Choice...\n";
        break;
    }
}
