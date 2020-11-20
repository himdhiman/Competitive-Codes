#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10000;
int arr[N];

// int dp[N][N];

// bool solve(int index, int target, int n){
// 	if(target == 0){
// 		return true;
// 	}
// 	if(n == 0){
// 		return false;
// 	}
// 	if(dp[target][n] != -1){
// 		return dp[target][n];
// 	}
// 	if(n-1 != index){
// 		if(arr[n-1] > target){
// 			return dp[target][n] = solve(index, target, n-1);
// 		}else{
// 			return dp[target][n] = solve(index, target-arr[n-1], n-1) || solve(index, target, n-1);
// 		}
// 	}else{
// 		return dp[target][n] = solve(index, target, n-1);
// 	}
// }

bool solve2(int index, int target, int n){
	bool dp[n+1][target+1];

	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	for(int i = 0; i <= target; i++){
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= target; j++){
			if(i-1 != index){
				if(arr[i-1] > j){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
				}
			}else{
				dp[i][j] = dp[i-1][j];	
			}
		}
	}
	return dp[n][target];
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		for(int i = 0; i < n; i++){
			// memset(dp, -1, sizeof dp);
			cout<<solve2(i, arr[i], n)<<" ";
		}
		cout<<endl;
	}

	


	return 0;
}