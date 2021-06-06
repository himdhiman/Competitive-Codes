#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int a, b, c;
int dp[4001];

int solve(int n){
	if(n < 0){
		return INT_MIN;
	}
	if(n == 0){
		return 0;
	}
	if(dp[n] != -1){
		return dp[n];
	}
	return dp[n] = 1 + max(solve(n-a), max(solve(n-b), solve(n-c)));
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n>>a>>b>>c;
	memset(dp, -1, sizeof dp);
	cout<<solve(n);


	return 0;
}