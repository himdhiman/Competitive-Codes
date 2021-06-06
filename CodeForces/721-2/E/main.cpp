#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int getoccSum(int start, int end){
	unordered_map<int, vector<int> > m;
	for(int i = start; i <= end; i++){
		m[arr[i]].push_back(i);
	}
	int ans = 0;
	for(auto x : m){
		ans += (x.second[x.second.size()-1] - x.second[0]);
	}
	return ans;
}

int solve(int start, int end, int n, int k){
	if(end >= n-1){
		return 0;
	}
	if(k == 0){
		return getoccSum(end-1, n-1);
	}
	return min(solve(start, end+1, n, k), getoccSum(start, end) + solve(end+1, end+1, n, k-1))
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}



	


	return 0;
}