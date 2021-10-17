#include<bits/stdc++.h>
using namespace std;

bool static cmp(pair<int,int>a,pair<int,int>b){
	return a.second < b.second;
}

void activitySelection(vector<pair<int,int> >arr){
	sort(arr.begin(),arr.end(),cmp);
	int cnt=0;
	int i=0;
	cout<<"Your selected activities are:\n";
	cout<<arr[i].first<<" "<<arr[i].second<<"\n";
	for(int j=1;j<arr.size();j++){
		if(arr[j].first>=arr[i].second){
			cout<<arr[j].first<<" "<<arr[j].second<<"\n";
			i=j;
		}
	}
}

int main(){
	vector<pair<int,int> > arr;
	cout<<"enter number of process:";
	int n;cin>>n;
	cout<<"enter start and finish time of process:\n";
	for(int i=0;i<n;i++){
		pair<int,int> p;
		int x,y;cin>>x>>y;
		p.first = x;
		p.second = y;
		arr.push_back(p);
	}
	activitySelection(arr);
}
