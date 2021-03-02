#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

// int dp[N][2000];

// int solve(int n, int m){
// 	if(n == 0 || m == 0){
// 		return 0;
// 	}
// 	if(dp[n][m] != -1){
// 		return dp[n][m];
// 	}
// 	if(arr[n-1] > m){
// 		return solve(n-1, m);
// 	}
// 	return dp[n][m] = max(1+solve(n-1, m-arr[n-1]), solve(n-1, m));
// }

int solve(int n, int m){
	int dp[2][m+1];
	for(int i = 0; i <= 1; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i <= m; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i-1] > j){
				dp[1][j] = dp[0][j];
			}else{
				dp[1][j] = max(1 + dp[0][j-arr[i-1]], dp[0][j]);
			}
		}
		for(int j = 0; j <= m; j++){
			dp[0][j] = dp[1][j];
		}
	}
	return dp[1][m];
}


int solve2(int n, int m){
	int freq[1001] = {0};
	for(int i = 0; i < n; i++){
		freq[arr[i]]++;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(i > m){
			return cnt;
		}
		while(m > 0 and freq[i] > 0){
			if(i > m){
				return cnt;
			}else{
				m -= i;
				cnt++;
				freq[i]--;
			}
		}
	}
	return cnt;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	for(int j = 1; j <= t; j++){
		int n, m;
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		// memset(dp, -1, sizeof dp);
		cout<<"Case #"<<j<<": "<<solve2(n, m)<<endl;

	}

	


	return 0;
}