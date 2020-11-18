#include<bits/stdc++.h>
#define int long long
#define MOD 720720
using namespace std;

const int N = 100005, K = 31; 
int arr[N];
int dp[N][K];

int solve(int n, int k){
	if(k == 0){
		return 1;
	}
	if(n == 0){
		return 0;
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	if(k == 1 and arr[n-1] == 0){
		return dp[n][k] = solve(n-1, k);
	}
	return dp[n][k] = ((solve(n-1, k-1) % MOD) + (solve(n-1, k) % MOD)) % MOD; 
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 


	int n, k;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cin>>k;
	memset(dp, -1, sizeof dp);
	if(k == 1){
		cout<<n;
	}else{
		cout<<solve(n, k);
	}
	


	return 0;
}