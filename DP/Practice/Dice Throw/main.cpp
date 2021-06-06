#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
int dp[N][N];


int solve(int n, int m, int sum){
	if(n == 0){
		if(sum == 0){
			return 1;
		}
		return 0;
	}

	if(sum < 0 or sum > m*n or sum < n){
		return 0;
	}

	if(dp[n][sum] != -1){
		return dp[n][sum];
	}

	int ans = 0;
	for(int i = 1; i <= m; i++){
		ans += solve(n-1, m, sum-i);
	}

	return dp[n][sum] = ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	memset(dp, -1, sizeof dp);
	cout<<solve(3, 6, 8);
	
	return 0;
}