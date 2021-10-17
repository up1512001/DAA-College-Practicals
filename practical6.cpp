#include<bits/stdc++.h>
using namespace std;


class practical6{
	public:
		void makingChange(vector<int>coins,int change){
			sort(coins.begin(),coins.end());
			int n=coins.size();
			vector<int> ans;
			for(int i=n-1;i>=0;i--){
				while(change>=coins[i]){
					change -= coins[i];
					ans.push_back(coins[i]);
				}
			}
			cout<<"required coins are: ";
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<"\n";
		}
		bool static cmp(pair<int,int> a,pair<int,int> b){
			double r1 = (double)a.first / (double)a.second;
			double r2 = (double)b.first / (double)b.second;
			return r1>r2;
		}
		void knapsack(vector<pair<int,int> >arr,int w){
			sort(arr.begin(),arr.end(),cmp);
			int curW = 0;
			double ans=0;
			for(int i=0;i<arr.size();i++){
				if(curW + arr[i].second <= w){
					curW += arr[i].second;
					ans += arr[i].first;
				}else{
					int rem = w - curW;
					ans += arr[i].first *((double)rem/(double)arr[i].second);
					break;
				}
			}
			cout<<"ans is : "<<ans<<"\n";
		}
};

int main(){
	int n;
	
	int c;
	cout<<"Enter choice from\n1)making change\n2)knapsack\n";
	cin>>c;
	
	switch(c){
		
		case 1:{
	
			cout<<"enter coins array size:\n";
		
			cin>>n;
			
			cout<<"enter coins array:\n";
			vector<int> arr(n);
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			cout<<"Enter change amount:";
			int change;cin>>change;
			
			practical6 o1;
			o1.	makingChange(arr,change);
			break;
		}
		case 2:{
			cout<<"Enter size of array:";
			cin>>n;
			
			cout<<"Enter pair value of value and weight array:";
			vector<pair<int,int> > arr;
			for(int i=0;i<n;i++){
				pair<int,int> p;
				int x,y;cin>>x>>y;
				p.first = x;
				p.second = y;
				arr.push_back(p);
			}
			cout<<"Enter weight capacity:";
			int W;cin>>W;
			practical6 o2;
			o2.	knapsack(arr,W);
			
			break;
		}
		default:
			cout<<"Enter valid input...\n";
			break;
			
	}
	
	
	
	
}
