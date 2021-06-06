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
		int n, k, f, u, v;
		cin>>n>>k>>f;
		vector<int> start;
		vector<int> end;
		for(int i = 0; i < n; i++){
			cin>>u>>v;
			start.push_back(u);
			end.push_back(v);
		}
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		bool flag = false;
		int ans = 0;
		for(int i = 0; i < start.size()-1; i++){
			if(start[i+1]-end[i] >= 0){
				ans += (start[i+1]-end[i]);
			}
		}
		if(start[0] >= 0){
			ans += start[0];
		}
		if(f-end[end.size()-1] >= 0){
			ans += f-end[end.size()-1];
		}
		if(ans >= k){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}