#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[10000][10000];

int solve(vector<int> v, int i, int j){
	if(j == -1){
		return 0;
	}
	if(i == j){
		return v[i];
	}
	if(i + 1 == j){
		return max(v[i], v[j]);
	}
	if(dp[i][j] != 0){
		return dp[i][j];
	}
	int ans1 = v[i] + min(solve(v, i+1, j-1), solve(v, i+2, j));
	int ans2 = v[j] + min(solve(v, i, j-2), solve(v, i+1, j-1));
	return dp[i][j] = max(ans2, ans1);
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i){
		cin>>v[i];
	}
	int j = v.size()-1;
	memset(dp, 0, sizeof dp);
	cout<<solve(v, 0, j);



	return 0;
}