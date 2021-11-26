#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        int m = nums[i];
        for(int j=i+1;j<nums.size();j++){
            if(m<nums[j]){
                m=nums[j];
            }
        }
        swap(m,nums[i]);
    }
}

void bubblesort(vector<int> &nums){
    bool flag=true;
    for(int i=0;i<nums.size()-1;i++){
        flag=true;
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                flag=false;
            }
        }
        if(flag){
            break;
        }
    }
}

void insertionsort(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        int j=i-1;
        int temp=nums[i];
        while(j>=0 && nums[i]>=temp){
            nums[j+1] = nums[j];
            j--;
        }
        swap(nums[j+1],temp);
    }
}

void merge(vector<int> &nums,int i,int k,int j){
    int a=i,b=k+1;
    vector<int> temp;
    while(a<=k && b<=j){
        if(nums[a]<=nums[b]){
            temp.push_back(nums[a++]);
        }else{
            temp.push_back(nums[b++]);
        }
    }
    while(a<=k){
        temp.push_back(nums[a++]);
    }
    while(b<=j){
        temp.push_back(nums[b++]);
    }
    for(int p=0;p<temp.size();p++,i++){
        nums[i]=temp[p];
    }
}

void mergesort(vector<int> &nums,int i,int j){
    if(i<j){
        int k=i+(j-i)/2;
        mergesort(nums,i,k);
        mergesort(nums,k+1,j);
        merge(nums,i,k,j);
    }
}

int partition(vector<int> &nums,int i,int j){
    int temp=nums[i],b=i-1;
    for(int a=i;a<j;a++){
        if(temp>=nums[a]){
            b++;
            swap(nums[a],nums[b]);
        }
    }
    swap(nums[b+1],nums[i]);
    return b+1;
}

void quicksort(vector<int> &nums,int i,int j){
    if(i<j){
        int pivot = partition(nums,i,j);
        quicksort(nums,i,pivot-1);
        quicksort(nums,pivot+1,j);
    }
}


void countsort(vector<int> &nums){
    vector<int> arr(*max_element(nums.begin(),nums.end())+1,0);
    for(int i=0;i<nums.size();i++){
        arr[nums[i]]++;
    }
    for(int i=1;i<arr.size();i++){
        arr[i]+=arr[i-1];
    }
    vector<int> temp(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        temp[arr[nums[i]]-1] = nums[i];
        arr[nums[i]]--;
    }
    for(int i=0;i<nums.size();i++){
        nums[i]=temp[i];
    }  
}

void CNT(vector<int> &nums,int dec){
    vector<int> cnt(10,0);
    for(int i=0;i<nums.size();i++){
        cnt[(nums[i]/dec)%10]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]+=cnt[i-1];
    }
    vector<int> temp(nums.size(),0);
    for(int i=nums.size()-1;i>=0;i--){
        temp[cnt[(nums[i]/dec)%10]-1] = nums[i];
        cnt[(nums[i]/dec)%10]--;
    }
    for(int i=0;i<nums.size();i++){
        nums[i]=temp[i];
    }
}

void radixsort(vector<int> &nums){
    int mx = *max_element(begin(nums),end(nums));
    for(int i=1;mx/i>0;i*=10){
        CNT(nums,i);
    }
}

void makingchange(vector<int> &nums,int change){
    sort(nums.begin(),nums.end());
    vector<int> ans;
    for(int i=nums.size()-1;i>=0;i--){
        while(change>=nums[i]){
            change-=nums[i];
            ans.push_back(nums[i]);
        }
    }
}

int main(){

}