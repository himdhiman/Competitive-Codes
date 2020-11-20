#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1001;
vector<int> v(N, 0);
int dp[N][N];

int solve(int l, int r){
	if(l > r){
		return 0;
	}
	if(l == r){
		return v[l];
	}
	if(l+1 == r){
		return max(v[l]*v[l+1], v[l]+v[l+1]);
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int p = 0;
	// int ans1 = -1, ans2 = -1, ans3 = -1, ans4 = -1;
	int ans1 = v[r] + solve(l, r-1);
	int ans2 = v[r]*v[r-1] + solve(l, r-2);
	// reverse(v.begin(), v.end());
	int ans3 = v[l] + solve(l+1, r);
	int ans4 = v[l]*v[l+1] + solve(l+2, r);
	p = max(ans1, max(ans2, max(ans3, ans4)));
	return dp[l][r] = p;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(0, n-1);
	


	return 0;
}