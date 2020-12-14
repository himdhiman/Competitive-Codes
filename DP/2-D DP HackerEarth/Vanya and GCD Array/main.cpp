#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 501;
int arr[N];

int dp[N][100];


int solve(int n, int i, int gcd){
	if(i == n){
		return gcd == 1;
	}
	if(dp[i][gcd] != -1){
		return dp[i][gcd];
	}
	
	int ans = solve(n, i+1, __gcd(gcd, arr[i])) + solve(n, i+1, gcd);
	if(ans >= MOD){
		ans -= MOD;
	}
	return dp[i][gcd] = ans;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; cin>>arr[i++])
	memset(dp, -1, sizeof dp);

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = ans + solve(n, i+1, arr[i]);
		if(ans >= MOD){
			ans -= MOD;
		}
	}
	cout<<ans;

	return 0;
}