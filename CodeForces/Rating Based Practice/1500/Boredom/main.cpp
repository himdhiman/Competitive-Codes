#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N] = {0};
int dp[N];

int solve(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return arr[1];
	}
	if(dp[n] != -1){
		return dp[n];
	}
	return dp[n] = max(solve(n-1), solve(n-2) + (n)*(arr[n]));
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, val;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>val;
		arr[val]++;
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(N-2);
	// dp[0] = 0;
	// dp[1] = arr[1];
	// for(int i = 2; i < N; i++){
	// 	dp[i] = max(dp[i-1], dp[i-2] + arr[i]*i);
	// }
	// cout<<dp[N-1];



	


	return 0;
}