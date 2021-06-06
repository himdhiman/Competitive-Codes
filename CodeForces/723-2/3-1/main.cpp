#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

// int solve(int n){
// 	int dp[2][n];
// 	dp[0][0] = (arr[0] >= 0 ? arr[0] : 0);
// 	dp[1][0] = 0;

// 	for(int i = 1; i < n; i++){
// 		int temp1 = ((dp[0][i-1] + arr[i]) >= 0 ? dp[0][i-1]+arr[i] : 0);
// 		int temp2 = ((dp[1][i-1] + arr[i]) >= 0 ? dp[1][i-1]+arr[i] : 0);
// 		dp[0][i] = max(temp1, temp2);
// 		dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
// 	}
// 	return max(dp[0][n-1], dp[1][n-1]);
// }

int solve4(int n){
	int dp[2001][2001];
	for(int i = 0; i <= 2000; i++){
		for(int j = 0; j <= 2000; j++){
			dp[i][j] = INT_MIN;
		}
	}
	dp[1][0] = 0;
	dp[1][1] = (arr[1] >= 0 ? arr[1] : 0);

	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if((dp[i-1][j-1] + arr[i]) >= 0){
				dp[i][j] = max(dp[i-1][j-1] + arr[i], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
			// dp[i][j] = ((dp[i-1][j-1]+arr[i]) >= 0 ? dp[i-1][j-1]+arr[i] : dp[i-1][j]);
		}
	}
	int idx = 0;
	int val = dp[n+1][0];
	for(int i = 1; i <= arr[n]; i++){
		if(dp[n+1][i] >= val){
			val = dp[n+1][i];
			idx = i;
		}
	}
	return idx;
}

int dp[2001][9001];

int solve2(int n, int i, int health){
	if(i == n){
		return 0;
	}
	if(dp[i][health] != -1){
		return dp[i][health];
	}
	if((health + arr[i]) < 0){
		return solve2(n, i+1, health);
	}
	return dp[i][health] = max(1 + solve2(n, i+1, health + arr[i]), solve2(n, i+1, health));
}

// int solve3(int n, int sum, int *dp){
// 	if(n == 0){
// 		return 0;
// 	}
// 	if(dp[n][sum] != -1){
// 		return dp[n][sum];
// 	}
// 	if((sum + arr[n-1]) < 0){
// 		return solve3(n-1, sum, dp);
// 	}
// 	return dp[n][sum] = max(1 + solve3(n-1, sum+arr[n-1], dp), solve3(n-1, sum, dp));
// }



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	// memset(dp, -1, sizeof dp);
	// int ans1 = solve(n);
	// int *dp = new int[n+1][ans1+1];
	// memset(dp, -1, sizeof dp);
	// cout<<solve2(n, 0, 0)<<endl;
	cout<<solve4(n)<<endl;
	// sort(arr, arr+n);
	// int cnt = 0;
	// int ans = 0;
	// int idx = n-1;
	// while(true){
	// 	if((ans + arr[idx]) >= 0){
	// 		cout<<arr[idx]<<" ";
	// 		ans += arr[idx];
	// 		cnt++;
	// 		idx--;
	// 	}else{
	// 		break;
	// 	}
	// }
	// cout<<cnt<<endl;
	


	return 0;
}