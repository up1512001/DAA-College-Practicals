#include<bits/stdc++.h>
using namespace std;
#define pb push_back
class Assignment1{

public:
    void printArray(vector<int>&nums){
        //cout<<"\nPrinting array:\n";
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<"\n";
        //cout<<"\nEnd of printing...\n";
    }

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

    // Bubble Sort
    void BubbleSort(vector<int>&nums){
        bool flag=true;
        for(int i=0;i<nums.size()-1;i++){
            flag = false;
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    flag=true;
                }
            }
            if(!flag)
                break;
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

    // Merge Sort
    void Merge(vector<int> &nums,int left,int mid,int right){
        int n1 = mid-left+1;
        int n2 = right - mid;
        int arr1[n1],arr2[n2];

        for(int i=0;i<n1;i++)
            arr1[i] = nums[left+i];
        for(int i=0;i<n2;i++)
            arr2[i] = nums[mid+1+i];

        int i=0,j=0,k=left;

        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                nums[k] = arr1[i++];
            }else{
                nums[k] = arr2[j++];
            }
            k++;
        }

        while(i<n1){
            nums[k++] = arr1[i++];
        }

        while(j<n2){
            nums[k++] = arr2[j++];
        }
        return;
    }
    void MergeSort(vector<int> &nums,int left,int right){
        if(left < right){
            int mid = left+(right-left)/2;
            MergeSort(nums,left,mid);
            MergeSort(nums,mid+1,right);
            Merge(nums,left,mid,right);
        }
        return;
    }

    // Quick Sort
    int Partition(vector<int>&nums,int low,int high){
        int pivot = nums[high];
        int i= low-1;

        for(int j=low;j<high;j++){
            if(nums[j]<=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
    void QuickSort(vector<int>&nums,int low,int high){
        if(low<high){
            int pivot = Partition(nums,low,high);
            QuickSort(nums,low,pivot-1);
            QuickSort(nums,pivot+1,high);
        }
    }

    // Count Sort
    void CountingSort(vector<int>&nums){
        int max = *max_element(begin(nums),end(nums));
        int min = *min_element(begin(nums),end(nums));
        int len = max-min+1;
        vector<int> count(nums.size(),0),op(nums.size());
        for(int i=0;i<nums.size();i++)
            count[nums[i]-min]++;
        for(int i=1;i<count.size();i++)
            count[i]+=count[i-1];
        for(int i=nums.size()-1;i>=0;i--){
            op[count[nums[i]-min]-1] = nums[i];
            count[nums[i]-min]--;
        }
        for(int i=0;i<op.size();i++)
            nums[i] = op[i];

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

    //Shell Sort
    void ShellSort(vector<int> &nums){
        for(int gap=nums.size()/2;gap>0;gap/=2){
            for(int i=0;i<nums.size();i++){
                int temp = nums[i];
                int j=i;
                for(;j>=gap && nums[j-gap]>temp;j-=gap){
                    nums[j] = nums[j-gap];
                }
                nums[j] = temp;
            }
        }
        return;
    }
};

int main(){

    vector<int> v1{10,2,13,15,19,2,18};
    vector<int> v2{31,41,59,26,41,48,101,99,78};
    vector<int> v3{41,31,69,16,38,62};
    vector<int> v4{50,40,20,70,15,35,20,60};
    vector<int> v5{4,5,1,7,8,9,2,88};
    vector<int> v6{6,0,2,1,3,4,6,1,3,2};
    vector<int> v7{329,457,657,839,436,720,355};
    vector<int> v8{20,35,18,8,14,41,3,39};
    Assignment1 o1;
    // selection sort
    cout<<"Before Selection Sort: ";
    o1.printArray(v1);
    o1.SelectionSort(v1);
    cout<<"After Selection Sort: ";
    o1.printArray(v1);

    // bubble sort
    cout<<"Before Bubble Sort: ";
    o1.printArray(v2);
    o1.BubbleSort(v2);
    cout<<"After Bubble Sort: ";
    o1.printArray(v2);

    // insertion sort
    cout<<"Before Insertion Sort: ";
    o1.printArray(v3);
    o1.InsertionSort(v3);
    cout<<"After Insertion Sort: ";
    o1.printArray(v3);

    // merge Sort
    cout<<"Before Merge Sort: ";
    o1.printArray(v4);
    o1.MergeSort(v4,0,v4.size()-1);
    cout<<"After Merge Sort: ";
    o1.printArray(v4);

    // quick sort
    cout<<"Before Quick Sort: ";
    o1.printArray(v5);
    o1.QuickSort(v5,0,v5.size()-1);
    cout<<"After Quick Sort: ";
    o1.printArray(v5);

    // counting sort
    cout<<"Before Counting Sort: ";
    o1.printArray(v6);
    o1.CountingSort(v6);
    cout<<"After Counting Sort: ";
    o1.printArray(v6);

    // radix sort
    cout<<"Before Radix Sort: ";
    o1.printArray(v7);
    o1.RadixSort(v7);
    cout<<"After Radix Sort: ";
    o1.printArray(v7);

    // shell sort
    cout<<"Before Shell Sort: ";
    o1.printArray(v8);
    o1.ShellSort(v8);
    cout<<"After Shell Sort: ";
    o1.printArray(v8);


}
