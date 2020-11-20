#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101;
int arr[N][N];
int dp[N][N];
int n, m;

int solve(int i, int j){
	if(i == n-1 and j == m-1){
		return 1;
	}
	if(arr[i+1][j] <= arr[i][j] and arr[i][j+1] <= arr[i][j]){
		return 1;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	if(j == m-1 ||(arr[i+1][j] > arr[i][j] and arr[i][j+1] <= arr[i][j])){
		return dp[i][j] = 1 + solve(i+1, j);
	}
	if(i == n-1 || (arr[i][j+1] > arr[i][j] and arr[i+1][j] <= arr[i][j])){
		return dp[i][j] = 1 + solve(i, j+1);
	}
	return dp[i][j] = 1 + max(solve(i, j+1), solve(i+1, j));
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>arr[i][j];
			}
		}
		memset(dp, -1, sizeof dp);
		cout<<solve(0, 0)<<endl;
	}

	


	return 0;
}