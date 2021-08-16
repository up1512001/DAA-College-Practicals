#include<bits/stdc++.h>
using namespace std;

class Practical4{
public:
    // Selection Sort
    void SelectionSort(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++){
            int mid=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[mid]){
                    mid=j;
                }
            }
            swap(nums[mid],nums[i]);
        }
        return;
    }

    // Insertion Sort
    void InsertionSort(vector<int> &nums){
        int temp;
        for(int i=0;i<nums.size();i++){
            temp = nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
        return;
    }

    // Linear Search
    void LinearSearch(vector<int> &nums,int val){
        for(int i=0;i<nums.size();i++){
            if(val == nums[i]){
                cout<<"Value Found At "<<i<<"th Index:\n";
                return;
            }
        }
        cout<<"Value Not Found...\n";
        return;
    }

    //Radix Sort
    void CSR(vector<int> &nums,int ind){
        vector<int> cnt(10,0),op(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            cnt[(nums[i]/ind)%10]++;
        }
        for(int i=1;i<10;i++)
            cnt[i]+=cnt[i-1];
        for(int i=nums.size()-1;i>=0;i--){
            op[cnt[(nums[i]/ind)%10]-1] = nums[i];
            cnt[(nums[i]/ind)%10]--;
        }
        for(int i=0;i<op.size();i++){
            nums[i] = op[i];
        }
        return;
    }
    void RadixSort(vector<int> &nums){
        int max = *max_element(begin(nums),end(nums));
        for(int ind=1;max/ind>0;ind*=10)
            CSR(nums,ind);
        return;
    }
    void printArray(vector<int>&nums){
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    srand(time(nullptr));
    Practical4 o1;
    vector<int> nums(10,0);
    for(int i=0;i<10;i++)
        nums[i] = rand();

    cout<<"1)Insertion Sort\n2) Selection Sort\n3)Linear Search\n4)Radix Sort\n";
    int c;cin>>c;
    switch(c){
    case 1:
        cout<<"Before Insertion Sort: ";
        o1.printArray(nums);
        o1.InsertionSort(nums);
        cout<<"After Insertion Sort: ";
        o1.printArray(nums);
        break;
    case 2:
        cout<<"Before Selection Sort: ";
        o1.printArray(nums);
        o1.SelectionSort(nums);
        cout<<"After Selection Sort: ";
        o1.printArray(nums);
        break;
    case 3:{
        int val;
        cout<<"Value for Searching:->";
        cin>>val;
        o1.LinearSearch(nums,val);
        break;
    }
    case 4:
        cout<<"Before Radix Sort: ";
        o1.printArray(nums);
        o1.RadixSort(nums);
        cout<<"After Radix Sort: ";
        o1.printArray(nums);
        break;
    default:
        cout<<"Enter Valid Choice...\n";
        break;
    }

}
