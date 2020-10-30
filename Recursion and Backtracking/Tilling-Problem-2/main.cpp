#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100000
using namespace std;

int Solve(int m, int n, int dp[]){
	if(n < 0){
		return 0;
	}
	if(dp[n] != 0){
		return dp[n];
	}
	if(n == 0){
		return 1;
	}
	return dp[n] = (Solve(m, n-1, dp)%MOD + Solve(m, n-m, dp)%MOD)%MOD;
}




int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int t;
	cin>>t;

	while(t--){
		int n, m;
		cin>>n>>m;
		int dp[MAX];
		memset(dp, 0, sizeof(dp));
		cout<<Solve(m, n, dp)<<endl;
	}
	return 0;
}