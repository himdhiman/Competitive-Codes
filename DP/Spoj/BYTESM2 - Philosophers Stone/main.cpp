#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101;

int arr[N][N];
int dp[N][N];

int solve(int n, int m, int i, int j){
	if(i == n){
		return 0;
	}
	if(dp[i][j] != 0){
		return dp[i][j];
	}
	int ans = 0;
	if(j == 0){
		ans = arr[i][j] + max(solve(n, m, i+1, j), solve(n, m, i+1, j+1));
	}else if(j == m-1){
		ans = arr[i][j] + max(solve(n, m, i+1, j), solve(n, m, i+1, j-1));
	}else{
		ans = arr[i][j] + max(solve(n, m, i+1, j), max(solve(n, m, i+1, j-1), solve(n, m, i+1, j+1)));
	}
	return dp[i][j] = ans;
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
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>arr[i][j];
			}
		}
		int ans = 0;
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < m; i++){
			ans = max(ans, solve(n, m, 0, i));
		}
		cout<<ans<<endl;
	}

	


	return 0;
}