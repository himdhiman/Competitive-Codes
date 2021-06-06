#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		map<int, int> mp;
		int n, m, k;
		cin>>n>>m>>k;
		for(int i = 0; i < k; i++){
			cin>>arr[i];
			if(arr[i] <= n){
				mp[arr[i]]++;
			}
		}
		vector<int> ans;
		for(auto x : mp){
			if(x.second > 1){
				ans.push_back(x.first);
			}
		}
		cout<<ans.size()<<" ";
		for(auto x : ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	


	return 0;
}