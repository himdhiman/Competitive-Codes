#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10005, K = 1005;
int arr[N];
int M;
int dp[N][K];

int solve(int n, int k){
	if(k == 0){
		return 0;
	}
	if(k > n || n == 0){
		return LLONG_MIN;
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	return dp[n][k] = max(arr[n]*(k % M) + solve(n-1, k-1), solve(n-1, k));
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, k, m;
	cin>>n>>k>>m;
	M = m;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(n, k);
	


	return 0;
}