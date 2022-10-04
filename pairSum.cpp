#include <bits/stdc++.h>
using namespace std;


pair<int,int> pairSum(int n, vector<int> arr, int t){

	unordered_set<int> uset;

	for(int i=0;i<n;i++){
		if(uset.find(t-arr[i])!=uset.end()){
			return make_pair(arr[i], t-arr[i]);
		}
		uset.insert(arr[i]);
	}

	return make_pair(-1,-1);
} 


int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	int n,t;
	vector<int> arr;
    int x;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
	}

	pair<int,int> ans = pairSum(n,arr,t);

	cout<<ans.first<<"  "<<ans.second<<endl;

}  
